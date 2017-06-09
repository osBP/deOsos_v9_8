//
//  triangleContainer.cpp
//  triangleContainer_01
//
//  Created by Oscar David Bravo Peña on 8/27/16.
//
//
#include "triangleContainer.h"

//-----------------------------
void triangleContainer::setBounds(float xa,float ya,float xb,float yb,float xc,float yc){
    X[0]=xa;
    X[1]=xb;
    X[2]=xc;
    Y[0]=ya;
    Y[1]=yb;
    Y[2]=yc;
    for (int i=1; i < 3 ; i++)
        for (int j=0 ; j<3 - 1; j++)
            if (Y[j] > Y[j+1]){
                float temp = Y[j];
                Y[j] = Y[j+1];
                Y[j+1] = temp;
                temp = X[j];
                X[j] = X[j+1];
                X[j+1] = temp;
            }
    cout<<"A( "<<X[0]<<" , "<<Y[0]<<" )"<<endl
        <<"B( "<<X[1]<<" , "<<Y[1]<<" )"<<endl
        <<"C( "<<X[2]<<" , "<<Y[2]<<" )"<<endl;
    getEquations();
    getDistancesABC();
}

//-----------------------------
void triangleContainer::getDistancesABC(){
    distAB = sqrtf( (X[1]-X[0])*(X[1]-X[0]) + (Y[1]-Y[0])*(Y[1]-Y[0]) );
    distBC = sqrtf( (X[2]-X[1])*(X[2]-X[1]) + (Y[2]-Y[1])*(Y[2]-Y[1]) );
    distCA = sqrtf( (X[0]-X[2])*(X[0]-X[2]) + (Y[0]-Y[2])*(Y[0]-Y[2]) );
    cout<<"distAB="<<distAB<<endl
        <<"distBC="<<distBC<<endl
        <<"distCA="<<distCA<<endl;
}

//--------------------------------------------------------
void triangleContainer::getDistancesPABC(float x,float y){
    distPA = sqrtf( (x-X[0])*(x-X[0]) + (y-Y[0])*(y-Y[0]) );
    distPB = sqrtf( (x-X[1])*(x-X[1]) + (y-Y[1])*(y-Y[1]) );
    distPC = sqrtf( (x-X[2])*(x-X[2]) + (y-Y[2])*(y-Y[2]) );
}

//-----------------------------
void triangleContainer::drawBoundaries(int gray){
    ofSetColor(gray);
    ofDrawLine(X[0], Y[0],Z[0], X[1], Y[1],Z[1]);
    ofSetColor(gray-100);
    ofDrawLine(X[1], Y[1],Z[1], X[2], Y[2],Z[2]);
    ofSetColor(gray-150);
    ofDrawLine(X[2], Y[2],Z[2], X[0], Y[0],Z[0]);
    //cout<<"drawn boundaries ok"<<endl;
}

//-----------------------------
bool triangleContainer::evaluatePoint(float x, float y, float r){
    getDistancesPABC(x, y);
    float evalCA=(Mca*x)+Bca;
    float evalBC=(Mbc*x)+Bbc;
    float evalAB=(Mab*x)+Bab;
    if ((Mab<0 && 0<Mca)||(Mab>0 && 0>Mca)) {//si las pendientes AB y CA tienen signos diferentes
        if ( ((X[0]<x && x<X[1])||(X[1]<x && x<X[0])) && ((Y[0]<y && y<Y[1])||(Y[1]<y && y<Y[0])) ) {//si se encuentra entre el punto A y B
            if(evalAB<y && y<evalBC){
                return true;
            }
            else
                return false;
        }
        if ( ((X[0]<x && x<X[2])||(X[2]<x && x<X[0]))&&((Y[0]<y && y<Y[2])||(Y[2]<y && y<Y[0])) ) {//si se encuentra entre el punto A y C
            if(evalCA<y && y<evalBC){
                return true;
                
            }
            else
                return false;
        }
        if ( ((X[1]<x && x<X[2])||(X[2]<x && x<X[1]))&&((Y[1]<y && y<Y[2])||(Y[2]<y && y<Y[1])) ) {//si se encuentre entre el Punto B y C
            if(x<X[0]){//del lado izquierdo de Xa
                if(evalAB<y && y<evalBC){
                    return true;
                    
                }
                else
                    return false;
            }
            if(x>X[0]){//del lado derecho de Xa
                if(evalCA<y && y<evalBC){
                    return true;
                    
                }
                else
                    return false;
            }
            
            
        }
        else
            return false;
    }
    if ((Mbc<0 && 0<Mca)||(Mbc>0 && 0>Mca)) {//si las pendientes BC y CA tienen signos diferentes
        if ( ((X[0]<x && x<X[2])||(X[2]<x && x<X[0])) && ((Y[0]<y && y<Y[2])||(Y[2]<y && y<Y[0])) ) {//si se encuentra entre el punto A y C
            if(evalAB<y && y<evalCA){
                return true;
            }
            else
                return false;
        }
        if ( ((X[1]<x && x<X[2])||(X[2]<x && x<X[1]))&&((Y[1]<y && y<Y[2])||(Y[2]<y && y<Y[1])) ) {//si se encuentra entre el punto B y C
            if(evalAB<y && y<evalBC){
                return true;
                
            }
            else
                return false;
        }
        if ( ((X[0]<x && x<X[1])||(X[1]<x && x<X[0]))&&((Y[0]<y && y<Y[1])||(Y[1]<y && y<Y[0])) ) {//si se encuentre entre el Punto A y B
            if(x<X[2]){//del lado izquierdo de Xc
                if(evalAB<y && y<evalCA){
                    return true;
                    
                }
                else
                    return false;
            }
            if(x>X[2]){//del lado derecho de Xc
                if(evalAB<y && y<evalBC){
                    return true;
                    
                }
                else
                    return false;
            }
            
            
        }
        else
            return false;
    }
    if ( (Mab<0 && Mbc<0 && Mca<0)||(Mab>0 && Mbc>0 && Mca>0)) {//si todas las pendientes tienen el mismo signo
        if ( ((X[0]<x && x<X[1])||(X[1]<x && x<X[0])) && ((Y[0]<y && y<Y[1])||(Y[1]<y && y<Y[0])) ) {//si se encuentra entre el punto A y B
            if(evalAB<y && y<evalCA){
                return true;
            }
            else
                return false;
        }
        if ( ((X[1]<x && x<X[2])||(X[2]<x && x<X[1]))&&((Y[1]<y && y<Y[2])||(Y[2]<y && y<Y[1])) ) {//si se encuentra entre el punto B y C
            if(evalBC<y && y<evalCA){
                return true;
                
            }
            else
                return false;
        }
        if ( ((X[0]<x && x<X[1])||(X[1]<x && x<X[0]))&&((Y[0]<y && y<Y[1])||(Y[1]<y && y<Y[0])) ) {//si se encuentre entre el Punto A y C
            if(x<X[1]){//del lado izquierdo de Xb
                if(evalAB<y && y<evalCA){
                    return true;
                    
                }
                else
                    return false;
            }
            if(x>X[1]){//del lado derecho de Xb
                if(evalBC<y && y<evalCA){
                    return true;
                    
                }
                else
                    return false;
            }
            
            
        }
        else
            return false;
    }
    
    
    cout<<"no match ";
    return false;
}

//----------------------
void triangleContainer::drawElements(){
    for (int i=0; i<elementsInContainer; i++) {
        ofSetColor(255);
        ofDrawSphere(Xe[i], Ye[i], 0,4);
        //cout<<"x["<<i<<"]="<<Xe[i]<<" y["<<i<<"]="<<Ye[i]<<" drawn"<<endl;
    }
}

//----------------------
void triangleContainer::setElements(int n, float minX, float maxX, float minY, float maxY, float minZ, float maxZ){
    Xe = new float [n];
    Ye = new float [n];
    Ze = new float [n];
    Re = new float [n];
    Xv = new float [n];
    Yv = new float [n];
    Zv = new float [n];
    
    for (elementsInContainer=0 ; elementsInContainer < n ; ) {
        float x=ofRandom(minX, maxX);
        float y=ofRandom(minY, maxY);
        float r=ofRandom(3, 5);
        cout<<" x= "<<x<<"  y= "<<y<<"  ";
        if( evaluatePoint(x,y,r) ){
            Xe[elementsInContainer]=x;
            Ye[elementsInContainer]=y;
            Re[elementsInContainer]=r;
            elementsInContainer++;
            cout<<elementsInContainer<<" approved"<<endl;
        }
        else
            cout<<"not approved"<<endl;
    }
    for (int i=0; i<elementsInContainer; i++) {
        Xv[i]=ofRandom(-1, 1);
        Yv[i]=ofRandom(-1, 1);
        Zv[i]=ofRandom(-1, 1);
    }
    n=0;
}

//-----------------------------
void triangleContainer::setMirrorSegment(char X,char Y){
    
}

//-----------------------------
void triangleContainer::getEquations(){
    if(X[0]!=X[1]){
        Mab=(Y[1]-Y[0])/(X[1]-X[0]);
        Bab=Y[0]-(Mab*X[0]);
    }
    else{
        
    }
    if(X[1]!=X[2]){
        Mbc=(Y[2]-Y[1])/(X[2]-X[1]);
        Bbc=Y[1]-(Mbc*X[1]);
    }
    else{
        
    }
    if(X[0]!=X[2]){
        Mca=(Y[2]-Y[0])/(X[2]-X[0]);
        Bca=Y[2]-(Mca*X[2]);
    }
    else{
        
    }
    cout<<Mab<<"*X[0]+"<<Bab<<endl
        <<Mbc<<"*X[1]+"<<Bbc<<endl
        <<Mca<<"*X[2]+"<<Bca<<endl;
}

void triangleContainer:: clear(){
    delete [] Xe;
    delete [] Ye;
    delete [] Ze;
    delete [] Re;
    delete [] Xv;
    delete [] Yv;
    delete [] Zv;
}

void triangleContainer:: setBounds(float xa,float ya,float za,float xb,float yb,float zb,float xc,float yc,float zc){
    X[0]=xa;
    X[1]=xb;
    X[2]=xc;
    Y[0]=ya;
    Y[1]=yb;
    Y[2]=yc;
    Z[0]=za;
    Z[1]=zb;
    Z[2]=zc;
    for (int i=1; i < 3 ; i++)
        for (int j=0 ; j<3 - 1; j++)
            if (Y[j] > Y[j+1]){
                float temp = Y[j];
                Y[j] = Y[j+1];
                Y[j+1] = temp;
                temp = X[j];
                X[j] = X[j+1];
                X[j+1] = temp;
                temp = Z[j];
                Z[j] = Z[j+1];
                Z[j+1] = temp;
            }
    cout<<"A( "<<X[0]<<" , "<<Y[0]<<" , "<<Z[0]<<" )"<<endl
        <<"B( "<<X[1]<<" , "<<Y[1]<<" , "<<Z[1]<<" )"<<endl
        <<"C( "<<X[2]<<" , "<<Y[2]<<" , "<<Z[2]<<" )"<<endl;
    getEquations();
    getDistancesABC();
}

void triangleContainer:: moveElements3D(){
    
    for (int i=0; i<elementsInContainer; i++) {
        if(evaluatePoint(Xe[i]+Xv[i], Ye[i]+Yv[i], Re[i])){
            Xe[i] += Xv[i];
            Ye[i] += Yv[i];
            Ze[i] += Zv[i];
        }
        else{
            Xe[i] -= Xv[i];
            Ye[i] -= Yv[i];
            Ze[i] -= Zv[i];
            
            Xv[i]*= -1;
            Yv[i]*= -1;
            Zv[i]*= -1;
        }
        Xv[i]+=ofSignedNoise(ofGetElapsedTimef()*ofRandom(0.1,2.9))/((float)elementsInContainer*(float)i);
        Yv[i]+=ofSignedNoise(ofGetElapsedTimef()*ofRandom(0.1,2.9))/((float)elementsInContainer*(float)i);
        Zv[i]+=ofSignedNoise(ofGetElapsedTimef()/(float)elementsInContainer);
    }
}

void triangleContainer::setBounds(ofPoint a, ofPoint b, ofPoint c){
    X[0]=a.x;
    X[1]=b.x;
    X[2]=c.x;
    Y[0]=a.y;
    Y[1]=b.y;
    Y[2]=c.y;
    Z[0]=a.z;
    Z[1]=b.z;
    Z[2]=c.z;
    for (int i=1; i < 3 ; i++)
        for (int j=0 ; j<3 - 1; j++)
            if (Y[j] > Y[j+1]){
                float temp = Y[j];
                Y[j] = Y[j+1];
                Y[j+1] = temp;
                temp = X[j];
                X[j] = X[j+1];
                X[j+1] = temp;
                temp = Z[j];
                Z[j] = Z[j+1];
                Z[j+1] = temp;
            }
    cout<<"A( "<<X[0]<<" , "<<Y[0]<<" , "<<Z[0]<<" )"<<endl
        <<"B( "<<X[1]<<" , "<<Y[1]<<" , "<<Z[1]<<" )"<<endl
        <<"C( "<<X[2]<<" , "<<Y[2]<<" , "<<Z[2]<<" )"<<endl;
    getEquations();
    getDistancesABC();
}
