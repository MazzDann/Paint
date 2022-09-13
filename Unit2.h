//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.NumberBox.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TImage *Image1;
	TListBox *ListBox1;
	TColorDialog *ColorDialog1;
	TLabel *revers;
	TShape *BackC;
	TShape *MainC;
	TButton *Save;
	TButton *Load;
	TShape *Shape3;
	TOpenPictureDialog *OpenPictureDialog1;
	TSavePictureDialog *SavePictureDialog1;
	TEdit *Edit1;
	TToggleSwitch *ToggleSwitch1;
	TPanel *Panel2;
	TBitBtn *add1;
	TBitBtn *min1;
	TPanel *Panel3;
	TBitBtn *undo;
	TImage *Image2;
	TBitBtn *Clear;
	TBitBtn *DinnerBone;
	TMainMenu *MainMenu1;
	TMenuItem *N121;
	TShape *Shape1;
	TMenuItem *Save1;
	TMenuItem *Load1;
	TMenuItem *Undo1;
	TSpeedButton *SpeedButton1;
	TMenuItem *New1;
	TBitBtn *Svect;
	TBitBtn *Lvect;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TMemo *VectLog;
	TMenuItem *Log1;
	TMenuItem *SaveV1;
	TMenuItem *SaveV2;
	TBitBtn *BitBtn1;
	TLabel *X_YLabl;
	TMenuItem *XandY1;
	TPanel *checkYX;
	void __fastcall FormResize(TObject *Sender);
	void __fastcall reversClick(TObject *Sender);
	void __fastcall MainCMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall SaveClick(TObject *Sender);
	void __fastcall LoadClick(TObject *Sender);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ToggleSwitch1Click(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall RemPClick(TObject *Sender);
	void __fastcall add1Click(TObject *Sender);
	void __fastcall undoClick(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall DinnerBoneClick(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SvectClick(TObject *Sender);
	void __fastcall LvectClick(TObject *Sender);
	void __fastcall Log1Click(TObject *Sender);
	void __fastcall Image1MouseLeave(TObject *Sender);
	void __fastcall Image2MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall VectLogMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall VectLogDblClick(TObject *Sender);
	void __fastcall Image2MouseEnter(TObject *Sender);
	void __fastcall VectLogMouseLeave(TObject *Sender);









private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
