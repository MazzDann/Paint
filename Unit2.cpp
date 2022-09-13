//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
short Mx[4],My[4];
bool Tf[128],TF,tmTF;
int tmpw=0,tmph=0;
int tamp,tamp1;
Graphics::TBitmap* spare=new Graphics::TBitmap();
Graphics::TBitmap* redod=new Graphics::TBitmap();
Graphics::TBitmap* tree=new Graphics::TBitmap();
Graphics::TBitmap* tmp1=new Graphics::TBitmap();
Graphics::TBitmap* tmp2=new Graphics::TBitmap();
AnsiString vect;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
for (short aA=0;aA<20;aA++){Tf[aA]=false;}TF=True;
Image1->Width=(Width-14)/1;
Image1->Height=Height-150;
VectLog->Height=Height-150;
VectLog->Top=96;
Image1->Top=96;
Image1->Left=1;
Panel3->Left=Width-Panel3->Width -14;
Panel1->Width=Width-14;
Panel1->Top=-1;
//tmpw=Width;tmph=Height;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormResize(TObject *Sender)
{
 Image1->Picture->Bitmap->SetSize((Width-14)/1, Height-150);
VectLog->Lines->Add("Resize");
VectLog->Lines->Add(IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));
VectLog->Lines->Add("Image1");
Panel3->Left=Width-Panel3->Width -14;
Panel1->Width=Width-14;
 Image2->SetBounds(Image1->Left,Image1->Top,(Width-14)/1,Height-150);
  VectLog->Left=(Width-14-VectLog->Width)/1;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::LvectClick(TObject *Sender)
{
 OpenDialog1->Filter="PainVect (*.pnv)|*.pnv|Any file (*.*)|*.*";

   for(int i=VectLog->Lines->Count-1; i>=0; i-- ){
	VectLog->Lines->Delete(i);
   }
   int mx,my,mx0,my0,mx1,my1,mx2,my2,color;
   AnsiString log,tmpp,ktmp;TCanvas* canv1, *canv2;TBitmap* pictV;
if (OpenDialog1->Execute()){
	VectLog->Lines->LoadFromFile(OpenDialog1->FileName);
	 int liness=VectLog->Lines->Count;
   for(int i=0; i<liness; i++ ){
   AnsiString l0g=VectLog->Lines->Strings[i];
   if(l0g=="CopyRect"){
   i++;tmpp=VectLog->Lines->Strings[i];
   ktmp=tmpp;
   i++;
   log=VectLog->Lines->Strings[i];
   mx0=StrToInt(log.SubString(1, log.Pos(" "))-1);
   log.Delete(1, log.Pos(" "));
   my0=StrToInt(log.SubString(1, log.Pos(" "))-1);
   log.Delete(1, log.Pos(" "));
   mx=StrToInt(log.SubString(1, log.Pos(" ")-1));
   log.Delete(1, log.Pos(" "));
   my=StrToInt(log);
   i++;tmpp=VectLog->Lines->Strings[i];
   if(tmpp=="spare"){canv2= spare->Canvas;
	}else if(tmpp=="redod"){canv2= redod->Canvas;
	}else if(tmpp=="tree"){canv2= tree->Canvas;
	}else if(tmpp=="tmp1"){canv2= tmp1->Canvas;
	}else if(tmpp=="tmp2"){canv2= tmp2->Canvas;
	}else if(tmpp=="Image1"){canv2= Image1->Canvas;
	}
   i++;
   log=VectLog->Lines->Strings[i];
   mx1=StrToInt(log.SubString(1, log.Pos(" ")-1));
   log.Delete(1, log.Pos(" "));
   my1=StrToInt(log.SubString(1, log.Pos(" "))-1);
   log.Delete(1, log.Pos(" "));
   mx2=StrToInt(log.SubString(1, log.Pos(" ")-1));
   log.Delete(1, log.Pos(" "));
   my2=StrToInt(log);
   if(ktmp=="spare"){spare->Canvas->CopyRect(Rect(mx0,my0,mx,my),canv2,Rect(mx1,my1,mx2,my2));;
	}else if(ktmp=="redod"){redod->Canvas->CopyRect(Rect(mx0,my0,mx,my),canv2,Rect(mx1,my1,mx2,my2));;
	}else if(ktmp=="tree"){tree->Canvas->CopyRect(Rect(mx0,my0,mx,my),canv2,Rect(mx1,my1,mx2,my2));;
	}else if(ktmp=="tmp1"){tmp1->Canvas->CopyRect(Rect(mx0,my0,mx,my),canv2,Rect(mx1,my1,mx2,my2));;
	}else if(ktmp=="tmp2"){tmp2->Canvas->CopyRect(Rect(mx0,my0,mx,my),canv2,Rect(mx1,my1,mx2,my2));;
	}else if(ktmp=="Image1"){Image1->Canvas->CopyRect(Rect(mx0,my0,mx,my),canv2,Rect(mx1,my1,mx2,my2));;
	}
   }else if(l0g=="Bitmap="){
   i++;tmpp=VectLog->Lines->Strings[i];
   if(tmpp=="spare"){canv2= spare->Canvas;
	}else if(tmpp=="redod"){canv2= redod->Canvas;
	}else if(tmpp=="tree"){canv2= tree->Canvas;
	}else if(tmpp=="tmp1"){canv2= tmp1->Canvas;
	}else if(tmpp=="tmp2"){canv2= tmp2->Canvas;
	}else if(tmpp=="Image1"){canv2= Image1->Canvas;
	}
VectLog->Lines->Add("Bitmap=");
VectLog->Lines->Add("Image1");
VectLog->Lines->Add("tmp2");
   }else if(l0g=="Resize"){
   i++;
   log=VectLog->Lines->Strings[i];
   mx=StrToInt(log.SubString(1, log.Pos(" ")-1));
   log.Delete(1, log.Pos(" "));
   my=StrToInt(log);
   i++;tmpp=VectLog->Lines->Strings[i];
   if(tmpp=="spare"){canv1= spare->Canvas;
	}else if(tmpp=="redod"){redod->SetSize(mx,my);
	}else if(tmpp=="tree"){tree->SetSize(mx,my);
	}else if(tmpp=="tmp1"){tmp1->SetSize(mx,my);
	}else if(tmpp=="tmp2"){tmp2->SetSize(mx,my);
	}else if(tmpp=="Image1"){Image1->Picture->Bitmap->SetSize(mx,my);
	}
   }

   //---------------------------------------------------------------------------
   else if(l0g=="PenColor"){
   i++;
   log=VectLog->Lines->Strings[i];
	color=StrToInt(log);
	Image1->Canvas->Pen->Color=(TColor)color;
}
   else if(l0g=="BrushStyle"){
   i++;
   log=VectLog->Lines->Strings[i];
	Image1->Canvas->Brush->Style=bsClear;
   }
   else if(l0g=="BrushColor"){
   i++;
   log=VectLog->Lines->Strings[i];
	color=StrToInt(log);
	Image1->Canvas->Brush->Color=(TColor)color;
   }
   else if(l0g=="FloodFill"){
   i++;
   log=VectLog->Lines->Strings[i];
   mx=StrToInt(log.SubString(1, log.Pos(" ")-1));
   log.Delete(1, log.Pos(" "));
   my=StrToInt(log);
   i++;
   log=VectLog->Lines->Strings[i];
	color=StrToInt(log);
   i++;
   log=VectLog->Lines->Strings[i];
   if(log=="fsSurface"){
	 Image1->Canvas->FloodFill(mx,my,(TColor)color,fsSurface);
	 }else if(log=="fsBorder"){
	 Image1->Canvas->FloodFill(mx,my,(TColor)color,fsBorder);
	 }
   }
   else if(l0g=="Rectangle"){
   i++;
   log=VectLog->Lines->Strings[i];
   mx0=StrToInt(log.SubString(1, log.Pos(" "))-1);
   log.Delete(1, log.Pos(" "));
   my0=StrToInt(log);
   i++;
   log=VectLog->Lines->Strings[i];
   mx=StrToInt(log.SubString(1, log.Pos(" ")-1));
   log.Delete(1, log.Pos(" "));
   my=StrToInt(log);
		  Image1->Canvas->Rectangle(mx0,my0,mx,my);
   }
   else if(l0g=="Ellipse"){
   i++;
   log=VectLog->Lines->Strings[i];
   mx0=StrToInt(log.SubString(1, log.Pos(" "))-1);
   log.Delete(1, log.Pos(" "));
   my0=StrToInt(log);
   i++;
   log=VectLog->Lines->Strings[i];
   mx=StrToInt(log.SubString(1, log.Pos(" ")-1));
   log.Delete(1, log.Pos(" "));
   my=StrToInt(log);
		  Image1->Canvas->Ellipse(mx0,my0,mx,my);
   }
   else if(l0g=="PenWidth"){
   i++;
   AnsiString log=VectLog->Lines->Strings[i];

Image1->Canvas->Pen->Width=StrToInt(log);
   }
   else if(l0g=="LineTo"){
   i++;
   log=VectLog->Lines->Strings[i];
   mx=StrToInt(log.SubString(1, log.Pos(" ")-1));
   log.Delete(1, log.Pos(" "));
   my=StrToInt(log);
	Image1->Canvas->LineTo(mx,my);
   }
   else if(l0g=="MoveTo"){
   i++;
   log=VectLog->Lines->Strings[i];
   mx=StrToInt(log.SubString(1, log.Pos(" ")-1));
   log.Delete(1, log.Pos(" "));
   my=StrToInt(log);
	Image1->Canvas->MoveTo(mx,my);
   }
   }
	}
	else
	  {throw(Exception("A? ?!."));}
	  }
//---------------------------------------------------------------------------
void __fastcall TForm2::reversClick(TObject *Sender)
{TColor Colorr = MainC->Brush->Color;
MainC->Brush->Color=BackC->Brush->Color;
BackC->Brush->Color=Colorr;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::MainCMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	ColorDialog1->Color = ((TShape*)Sender)->Brush->Color;
	 if(!ColorDialog1->Execute()) return;
	 ((TShape*)Sender)->Brush->Color = ColorDialog1->Color;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SaveClick(TObject *Sender)
{
SavePictureDialog1->DefaultExt=".bmp";
 SavePictureDialog1->Filter="Bitmaps (*.bmp)|*.bmp";
 if (SavePictureDialog1->Execute())
 {
   Image1->Picture->Bitmap->SaveToFile(SavePictureDialog1->FileName);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::LoadClick(TObject *Sender)
{
 SavePictureDialog1->Filter="Bitmaps (*.bmp)|*.bmp";
if(OpenPictureDialog1->Execute()){
	 Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
  }
}

void __fastcall TForm2::SvectClick(TObject *Sender)
{

SaveDialog1->DefaultExt=".pnv";
 SaveDialog1->Filter="PainVect (*.pnv)|*.pnv|Any file (*.*)|*.*";
 if (SaveDialog1->Execute())
 {
	  VectLog->Lines->SaveToFile(SaveDialog1->FileName);
	if (FileExists(SaveDialog1->FileName)){
	 // throw(Exception("Don`t overwrite file!!"));
	  }
 }
}

void __fastcall TForm2::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
 if (!ToggleSwitch1->Tag){Image1->Canvas->Brush->Color=BackC->Brush->Color;
VectLog->Lines->Add("BrushColor");
VectLog->Lines->Add(BackC->Brush->Color);
 }
else{Image1->Canvas->Brush->Style=bsClear;
VectLog->Lines->Add("BrushStyle");
VectLog->Lines->Add("bsClear");
}
 Image1->Canvas->Pen->Color=MainC->Brush->Color;
VectLog->Lines->Add("PenColor");
VectLog->Lines->Add(MainC->Brush->Color);
redod->Width=Image1->Width;
VectLog->Lines->Add("Resize");
VectLog->Lines->Add(IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));
VectLog->Lines->Add("redod");
redod->Height=Image1->Height;
VectLog->Lines->Add("CopyRect");
VectLog->Lines->Add("redod");
VectLog->Lines->Add(IntToStr(0)+" "+IntToStr(0)+" "+IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));
VectLog->Lines->Add("Image1");
VectLog->Lines->Add(IntToStr(0)+" "+IntToStr(0)+" "+IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));
 redod->Canvas->CopyRect(
 Rect(0, 0, Image1->Width, Image1->Height)
 ,Image1->Canvas
 ,Rect(0, 0, Image1->Width, Image1->Height)
 );
//spare->Canvas->CopyRect(Rect(-1, -1, Image1->Width, Image1->Height),Image1->Canvas,Rect(Image1->Width, Image1->Height, -1, -1));


switch(ListBox1->ItemIndex){
case -1:return;break;
 case 5:{
 Image1->Canvas->FloodFill(X, Y, (TColor)Image1->Canvas->Pixels[X][Y], fsSurface);
VectLog->Lines->Add("FloodFill");
VectLog->Lines->Add(IntToStr(X)+" "+IntToStr(Y));
VectLog->Lines->Add(Image1->Canvas->Pixels[X][Y]);
VectLog->Lines->Add("fsSurface");
break;}
case 6:case 7:
 Shape1->Left=X+Image1->Left;
 Shape1->Top=Y+Image1->Top;
 Shape1->Height=0;
 Shape1->Width=0;
 Shape1->Visible=True;
break;
case 8:
MainC->Brush->Color=Image1->Canvas->Pixels[X][Y];
VectLog->Lines->Add("BrushColor");
VectLog->Lines->Add(Image1->Canvas->Pixels[X][Y]);

 default:
break;
}
Image1->Canvas->Pen->Width=StrToInt(Edit1->Text);
VectLog->Lines->Add("PenWidth");
VectLog->Lines->Add(Edit1->Text);

Mx[0]=X;My[0]=Y;
   Image1->Canvas->MoveTo(X,Y);
VectLog->Lines->Add("MoveTo");
VectLog->Lines->Add(IntToStr(X)+" "+IntToStr(Y));
   Image1->Canvas->Pen->Color=MainC->Brush->Color;
VectLog->Lines->Add("PenColor");
VectLog->Lines->Add(MainC->Brush->Color);
 Tf[ListBox1->ItemIndex]=True;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton1Click(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
X_YLabl->Caption=IntToStr(X)+":"+IntToStr(Y);
switch(ListBox1->ItemIndex){
case -1:return;
case 0:if(Tf[ListBox1->ItemIndex]){
Image1->Canvas->LineTo(X,Y);
VectLog->Lines->Add("LineTo");
VectLog->Lines->Add(IntToStr(X)+" "+IntToStr(Y));}
break;
case 1:if(Tf[ListBox1->ItemIndex]){
 Image1->Canvas->Pen->Color=BackC->Brush->Color;
VectLog->Lines->Add("PenColor");
VectLog->Lines->Add(BackC->Brush->Color);
Image1->Canvas->LineTo(X,Y);
VectLog->Lines->Add("LineTo");
VectLog->Lines->Add(IntToStr(X)+" "+IntToStr(Y));
}break;
 case 6:case 7:if(Tf[ListBox1->ItemIndex]){
 Shape1->SetBounds(Mx[0]+Image1->Left,My[0]+Image1->Top,X-(Image1->Left+Shape1->Left),Y-My[0]);
 }break;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
    Shape1->Visible=False;
switch(ListBox1->ItemIndex){
case -1:return;
case 3:if(Tf[ListBox1->ItemIndex])
 Image1->Canvas->Ellipse(Mx[0],My[0],X,Y);
VectLog->Lines->Add("Ellipse");
VectLog->Lines->Add(IntToStr(Mx[0])+" "+IntToStr(My[0]));
VectLog->Lines->Add(IntToStr(X)+" "+IntToStr(Y));
 Tf[ListBox1->ItemIndex]=False;
 break;
case 2:if(Tf[ListBox1->ItemIndex])
Image1->Canvas->LineTo(X,Y);
VectLog->Lines->Add("LineTo");
VectLog->Lines->Add(IntToStr(X)+" "+IntToStr(Y));
 Tf[ListBox1->ItemIndex]=False;
 break;
case 4:if(Tf[ListBox1->ItemIndex])
 Image1->Canvas->Rectangle(Mx[0],My[0],X,Y);
VectLog->Lines->Add("Rectangle");
VectLog->Lines->Add(IntToStr(Mx[0])+" "+IntToStr(My[0]));
VectLog->Lines->Add(IntToStr(X)+" "+IntToStr(Y));
 Tf[ListBox1->ItemIndex]=False;
 break;
case 5:if(Tf[ListBox1->ItemIndex])
 Tf[ListBox1->ItemIndex]=False;
 break;
 case 6:
 Tf[ListBox1->ItemIndex]=False;
if(TF){
spare->SetSize((X-Mx[0]>0)? X-Mx[0]: -(X-Mx[0])
,(X-My[0]>0)? X-My[0]: -(X-My[0]));
//spare->Width=((X-Mx[0]>0)? X-Mx[0]: -(X-Mx[0]));
//spare->Height=((X-My[0]>0)? X-My[0]: -(X-My[0]));
spare->Transparent = true;spare->TransparentColor = BackC->Brush->Color;
 TRect TMPR=Rect(Mx[0], Mx[0], X, Y);

VectLog->Lines->Add("CopyRect");
VectLog->Lines->Add("spare");
VectLog->Lines->Add(IntToStr(-1)+" "+IntToStr(-1)
+" "+IntToStr(spare->Width)+" "+IntToStr(spare->Height));
VectLog->Lines->Add("Image1");
VectLog->Lines->Add(IntToStr(((Mx[0]>X)?X:Mx[0]))+" "+IntToStr(((My[0]>Y)?Y:My[0]))
+" "+IntToStr(((Mx[0]<X)?X:Mx[0]))+" "+IntToStr(((My[0]<Y)?Y:My[0])));

 spare->Canvas->CopyRect(
 Rect(-1, -1, spare->Width, spare->Height)
 ,Image1->Canvas
 ,Rect(((Mx[0]>X)?X:Mx[0]), ((My[0]>Y)?Y:My[0]),((Mx[0]<X)?X:Mx[0]), ((My[0]<Y)?Y:My[0])));
 TF=false;
											}else{
	 Image1->Canvas->CopyRect(
	 Rect(((Mx[0]>X)?X:Mx[0]), ((My[0]>Y)?Y:My[0]),((Mx[0]<X)?X:Mx[0]), ((My[0]<Y)?Y:My[0]))
	 ,spare->Canvas
	 ,Rect(-1, -1, spare->Width, spare->Height));

VectLog->Lines->Add("CopyRect");
VectLog->Lines->Add("Image1");
VectLog->Lines->Add(IntToStr(((Mx[0]>X)?X:Mx[0]))+" "+IntToStr(((My[0]>Y)?Y:My[0]))
+" "+IntToStr(((Mx[0]<X)?X:Mx[0]))+" "+IntToStr(((My[0]<Y)?Y:My[0])));
VectLog->Lines->Add("spare");
VectLog->Lines->Add(IntToStr(-1)+" "+IntToStr(-1)
+" "+IntToStr(spare->Width)+" "+IntToStr(spare->Height));

 TF=true;
 }
break;
 case 7:{

 if (!ToggleSwitch1->Tag){Image1->Canvas->Brush->Color=BackC->Brush->Color;
VectLog->Lines->Add("BrushColor");
VectLog->Lines->Add(BackC->Brush->Color);
 }
else{Image1->Canvas->Brush->Style=bsClear;
VectLog->Lines->Add("BrushStyle");
VectLog->Lines->Add("bsClear");
}
	Image1->Canvas->Pen->Color=BackC->Brush->Color;
VectLog->Lines->Add("PenColor");
VectLog->Lines->Add(BackC->Brush->Color);
	Image1->Canvas->Rectangle(Mx[0]+(X-Mx[0])*2/5,My[0]+(Y-My[0])*2/3,X-(X-Mx[0])*2/5,Y);
VectLog->Lines->Add("Rectangle");
VectLog->Lines->Add(IntToStr(Mx[0]+(X-Mx[0])*2/5)+" "+IntToStr(My[0]+(Y-My[0])*2/3));
VectLog->Lines->Add(IntToStr(X-(X-Mx[0])*2/5)+" "+IntToStr(Y));
	Image1->Canvas->Pen->Color=MainC->Brush->Color;
VectLog->Lines->Add("PenColor");
VectLog->Lines->Add(MainC->Brush->Color);

Image1->Canvas->MoveTo(Mx[0],My[0]+(Y-My[0])*2/3);
	VectLog->Lines->Add("MoveTo");
VectLog->Lines->Add(IntToStr(Mx[0])+" "+IntToStr(My[0]+(Y-My[0])*2/3));
Image1->Canvas->LineTo(X,My[0]+(Y-My[0])*2/3);
VectLog->Lines->Add("LineTo");
VectLog->Lines->Add(IntToStr(X)+" "+IntToStr(My[0]+(Y-My[0])*2/3));

Image1->Canvas->MoveTo(Mx[0]+(X-Mx[0])/6,My[0]+(Y-My[0])/3);
VectLog->Lines->Add("MoveTo");
VectLog->Lines->Add(IntToStr(Mx[0]+(X-Mx[0])/6)+" "+IntToStr(My[0]+(Y-My[0])/3));
Image1->Canvas->LineTo(X-(X-Mx[0])/6,My[0]+(Y-My[0])/3);
VectLog->Lines->Add("LineTo");
VectLog->Lines->Add(IntToStr(X-(X-Mx[0])/6)+" "+IntToStr(My[0]+(Y-My[0])/3));

Image1->Canvas->MoveTo(Mx[0],My[0]+(Y-My[0])*2/3);
VectLog->Lines->Add("MoveTo");
VectLog->Lines->Add(IntToStr(Mx[0])+" "+IntToStr(My[0]+(Y-My[0])*2/3));
Image1->Canvas->LineTo(Mx[0]+(X-Mx[0])*3/10,My[0]+(Y-My[0])/3);
VectLog->Lines->Add("LineTo");
VectLog->Lines->Add(IntToStr(Mx[0]+(X-Mx[0])*3/10)+" "+IntToStr(My[0]+(Y-My[0])/3));

Image1->Canvas->MoveTo(X,My[0]+(Y-My[0])*2/3);
VectLog->Lines->Add("MoveTo");
VectLog->Lines->Add(IntToStr(X)+" "+IntToStr(My[0]+(Y-My[0])*2/3));
Image1->Canvas->LineTo(X-(X-Mx[0])*3/10,My[0]+(Y-My[0])/3);
VectLog->Lines->Add("LineTo");
VectLog->Lines->Add(IntToStr(X-(X-Mx[0])*3/10)+" "+IntToStr(My[0]+(Y-My[0])/3));

Image1->Canvas->MoveTo(Mx[0]+(X-Mx[0])/6,My[0]+(Y-My[0])/3);
VectLog->Lines->Add("MoveTo");
VectLog->Lines->Add(IntToStr(Mx[0]+(X-Mx[0])/6)+" "+IntToStr(My[0]+(Y-My[0])/3));
Image1->Canvas->LineTo(Mx[0]+(X-Mx[0])/2,My[0]);
VectLog->Lines->Add("LineTo");
VectLog->Lines->Add(IntToStr(Mx[0]+(X-Mx[0])/2)+" "+IntToStr(My[0]));
Image1->Canvas->LineTo(X-(X-Mx[0])/6,My[0]+(Y-My[0])/3);
VectLog->Lines->Add("LineTo");
VectLog->Lines->Add(IntToStr(X-(X-Mx[0])/6)+" "+IntToStr(My[0]+(Y-My[0])/3));

int tmp[2];
tmp[0]=((X-Mx[0])/3>0)?(X-Mx[0])/3: -(X-Mx[0])/3 ;
tmp[1]=((Y-My[0])/3>0)?(Y-My[0])/3:-(Y-My[0])/3;
 if (!ToggleSwitch1->Tag & tmp[0]>2 &  tmp[1]>2){
 Image1->Canvas->Brush->Color=MainC->Brush->Color;
VectLog->Lines->Add("BrushColor");
VectLog->Lines->Add(MainC->Brush->Color);
   Image1->Canvas->FloodFill(Mx[0]+(X-Mx[0])/2, My[0]+(Y-My[0])/2, MainC->Brush->Color, fsBorder);
   Image1->Canvas->FloodFill(Mx[0]+(X-Mx[0])/2, My[0]+(Y-My[0])/6, MainC->Brush->Color, fsBorder);
VectLog->Lines->Add("FloodFill");
VectLog->Lines->Add(IntToStr(Mx[0]+(X-Mx[0])/2)+" "+IntToStr(My[0]+(Y-My[0])/2));
VectLog->Lines->Add(MainC->Brush->Color);
VectLog->Lines->Add("fsBorder");
VectLog->Lines->Add("FloodFill");
VectLog->Lines->Add(IntToStr(Mx[0]+(X-Mx[0])/2)+" "+IntToStr(My[0]+(Y-My[0])/6));
VectLog->Lines->Add(MainC->Brush->Color);
VectLog->Lines->Add("fsBorder");

 }

 if (!ToggleSwitch1->Tag){Image1->Canvas->Brush->Color=BackC->Brush->Color;
VectLog->Lines->Add("BrushColor");
VectLog->Lines->Add(BackC->Brush->Color);
 }
else{Image1->Canvas->Brush->Style=bsClear;
VectLog->Lines->Add("BrushStyle");
VectLog->Lines->Add("bsClear");
}
 Image1->Canvas->Pen->Color=MainC->Brush->Color;
VectLog->Lines->Add("PenColor");
VectLog->Lines->Add(MainC->Brush->Color);
}
 break;
 default: Tf[ListBox1->ItemIndex]=False;break;

}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::undoClick(TObject *Sender)
{
tmp1->SetSize(Image1->Width, Image1->Height);
VectLog->Lines->Add("Resize");
VectLog->Lines->Add(IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));
VectLog->Lines->Add("tmp1");
tmp1->Canvas->CopyRect(
 Rect(-1, -1, Image1->Width, Image1->Height)
 ,Image1->Canvas
 ,Rect(-1, -1, Image1->Width, Image1->Height)
 );
Image1->Canvas->CopyRect(
 Rect(-1, -1, Image1->Width, Image1->Height)
 ,redod->Canvas
 ,Rect(-1, -1, Image1->Width, Image1->Height)
 );
 redod->Canvas->CopyRect(
 Rect(-1, -1, Image1->Width, Image1->Height)
 ,tmp1->Canvas
 ,Rect(-1, -1, Image1->Width, Image1->Height)
 );
VectLog->Lines->Add("CopyRect");
VectLog->Lines->Add("tmp1");
VectLog->Lines->Add(IntToStr(-1)+" "+IntToStr(-1)
+" "+IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));
VectLog->Lines->Add("Image1");
VectLog->Lines->Add(IntToStr(-1)+" "+IntToStr(-1)
+" "+IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));

VectLog->Lines->Add("CopyRect");
VectLog->Lines->Add("Image1");
VectLog->Lines->Add(IntToStr(-1)+" "+IntToStr(-1)
+" "+IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));
VectLog->Lines->Add("redod");
VectLog->Lines->Add(IntToStr(-1)+" "+IntToStr(-1)
+" "+IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));


VectLog->Lines->Add("CopyRect");
VectLog->Lines->Add("redod");
VectLog->Lines->Add(IntToStr(-1)+" "+IntToStr(-1)
+" "+IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));
VectLog->Lines->Add("tmp1");
VectLog->Lines->Add(IntToStr(-1)+" "+IntToStr(-1)
+" "+IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ClearClick(TObject *Sender)
{
tmp2->SetSize(Image1->Width, Image1->Height);
VectLog->Lines->Add("Resize");
VectLog->Lines->Add(IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));
VectLog->Lines->Add("tmp2");
Image1->Picture->Bitmap=tmp2;
VectLog->Lines->Add("Bitmap=");
VectLog->Lines->Add("tmp2");
VectLog->Lines->Add("Image1");
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DinnerBoneClick(TObject *Sender)
{
  Image1->Canvas->CopyRect(Rect(-1, -1,
  Image1->Width, Image1->Height)
  ,Image1->Canvas,Rect(Image1->Width, Image1->Height
  , -1, -1));
VectLog->Lines->Add("CopyRect");
VectLog->Lines->Add("Image1");
VectLog->Lines->Add(IntToStr(-1)+" "+IntToStr(-1)
+" "+IntToStr(Image1->Width)+" "+IntToStr(Image1->Height));
VectLog->Lines->Add("Image1");
VectLog->Lines->Add(IntToStr(Image1->Width)+" "+IntToStr(Image1->Height)
+" "+IntToStr(-1)+" "+IntToStr(-1));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ToggleSwitch1Click(TObject *Sender)
{
 if(ToggleSwitch1->Tag){
 ToggleSwitch1->Tag=0;
 }                    else{
	 ToggleSwitch1->Tag=1;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
Edit1->MaxLength = 3;
switch(Key){
case VK_BACK:return;break;
case VK_DOWN://if(StrToInt(Edit1->Text)>1)
{Edit1->Text=StrToInt(Edit1->Text)-1;}break;
case VK_UP://if(StrToInt(Edit1->Text)<1000)
{Edit1->Text=StrToInt(Edit1->Text)+1;}break;
}
	if(Edit1->Text!=""& Key == L'0'){return;}
	if( (Key < L'1') || (Key > L'9') )
	{
		Key = 0;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RemPClick(TObject *Sender)
{
if(StrToInt(Edit1->Text)>1){Edit1->Text=StrToInt(Edit1->Text)-1;}

}
//---------------------------------------------------------------------------
void __fastcall TForm2::add1Click(TObject *Sender)
{
if(StrToInt(Edit1->Text)<1000){Edit1->Text=StrToInt(Edit1->Text)+1;}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Log1Click(TObject *Sender)
{
if(Image2->Visible){
VectLog->Visible=false;
 Image2->Visible=false;
 Panel1->Enabled=true;
 Image1->Enabled=true;
}else{
VectLog->Visible=true;
 Image2->Visible=true;
 checkYX->Visible=true;
 Panel1->Enabled=false;
 Image1->Enabled=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image1MouseLeave(TObject *Sender)
{
X_YLabl->Caption="";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image2MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
{checkYX->Left=X+Image1->Left;}
checkYX->Top=Y+Image1->Top;
checkYX->Caption=IntToStr(X)+":"+IntToStr(Y);
//ShowMessage("a");
}
//---------------------------------------------------------------------------
void __fastcall TForm2::VectLogMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
checkYX->Left=X+VectLog->Left;
checkYX->Left=X+VectLog->Left;
checkYX->Top=Y+VectLog->Top;
checkYX->Caption=IntToStr(X+VectLog->Left)+":"+IntToStr(Y+2);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::VectLogDblClick(TObject *Sender)
{
if(VectLog->Left>2){
VectLog->Left=0;}else{VectLog->Left=(Width-14-VectLog->Width)/1;}
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image2MouseEnter(TObject *Sender)
{
if(Image2->Visible){
 checkYX->Visible=true;
}else{
 checkYX->Visible=false;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::VectLogMouseLeave(TObject *Sender)
{
 checkYX->Visible=false;
}
//---------------------------------------------------------------------------

