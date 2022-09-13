object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'My Pain'
  ClientHeight = 664
  ClientWidth = 924
  Color = clSilver
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 2
    Top = 87
    Width = 585
    Height = 291
    OnMouseDown = Image1MouseDown
    OnMouseLeave = Image1MouseLeave
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object Shape1: TShape
    Left = 486
    Top = 400
    Width = 65
    Height = 65
    Brush.Style = bsClear
    Enabled = False
    Pen.Color = clGray
    Pen.Style = psDashDotDot
    Visible = False
  end
  object Image2: TImage
    Left = 269
    Top = 446
    Width = 105
    Height = 105
    Visible = False
    OnMouseEnter = Image2MouseEnter
    OnMouseLeave = VectLogMouseLeave
    OnMouseMove = Image2MouseMove
  end
  object Panel1: TPanel
    Left = 2
    Top = 0
    Width = 825
    Height = 89
    BevelOuter = bvNone
    TabOrder = 0
    object BackC: TShape
      Left = 135
      Top = 49
      Width = 33
      Height = 33
      OnMouseDown = MainCMouseDown
    end
    object MainC: TShape
      Left = 152
      Top = 32
      Width = 33
      Height = 33
      Brush.Color = clBlack
      OnMouseDown = MainCMouseDown
    end
    object Shape3: TShape
      Left = 135
      Top = 9
      Width = 17
      Height = 17
    end
    object revers: TLabel
      Left = 170
      Top = 59
      Width = 15
      Height = 23
      Caption = #8644
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = reversClick
    end
    object SpeedButton1: TSpeedButton
      Left = 191
      Top = 31
      Width = 23
      Height = 22
      AllowAllUp = True
      GroupIndex = 1
      OnClick = SpeedButton1Click
    end
    object X_YLabl: TLabel
      Left = 276
      Top = 39
      Width = 3
      Height = 13
    end
    object ListBox1: TListBox
      Left = 8
      Top = 9
      Width = 121
      Height = 73
      ItemHeight = 13
      Items.Strings = (
        'Pen'
        'Erase'
        'Line'
        'Circle'
        'Rectangle'
        'Brush'
        'Cut'
        'Vect tree'
        'Copy_Color')
      TabOrder = 0
    end
    object ToggleSwitch1: TToggleSwitch
      Left = 191
      Top = 59
      Width = 72
      Height = 20
      FrameColor = clMenu
      TabOrder = 1
      ThumbColor = clHighlight
      OnClick = ToggleSwitch1Click
    end
    object Panel2: TPanel
      Left = 275
      Top = 58
      Width = 72
      Height = 30
      AutoSize = True
      TabOrder = 2
      object Edit1: TEdit
        Left = 1
        Top = 2
        Width = 50
        Height = 27
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = '1'
        OnKeyPress = Edit1KeyPress
      end
      object add1: TBitBtn
        Left = 57
        Top = 1
        Width = 14
        Height = 14
        Caption = '+'
        TabOrder = 1
        OnClick = add1Click
      end
      object min1: TBitBtn
        Left = 57
        Top = 15
        Width = 14
        Height = 14
        Caption = '-'
        TabOrder = 2
        OnClick = RemPClick
      end
    end
    object Panel3: TPanel
      Left = 656
      Top = 6
      Width = 159
      Height = 76
      BevelOuter = bvNone
      TabOrder = 3
      object Save: TButton
        Left = 112
        Top = 1
        Width = 47
        Height = 25
        Caption = 'Save'
        TabOrder = 0
        OnClick = SaveClick
      end
      object Load: TButton
        Left = 112
        Top = 32
        Width = 47
        Height = 25
        Caption = 'Load'
        TabOrder = 1
        OnClick = LoadClick
      end
      object undo: TBitBtn
        Left = 0
        Top = 19
        Width = 20
        Height = 26
        Caption = #8630
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = undoClick
      end
      object Clear: TBitBtn
        Left = 0
        Top = 51
        Width = 38
        Height = 25
        Caption = 'Clear'
        TabOrder = 3
        OnClick = ClearClick
      end
      object Svect: TBitBtn
        Left = 56
        Top = 1
        Width = 50
        Height = 25
        Caption = 'Save vct'
        TabOrder = 4
        OnClick = SvectClick
      end
      object Lvect: TBitBtn
        Left = 57
        Top = 32
        Width = 49
        Height = 25
        Caption = 'Load vct'
        TabOrder = 5
        OnClick = LvectClick
      end
    end
    object DinnerBone: TBitBtn
      Left = 392
      Top = 57
      Width = 75
      Height = 25
      Caption = 'DinnerBone'
      TabOrder = 4
      OnClick = DinnerBoneClick
    end
    object BitBtn1: TBitBtn
      Left = 512
      Top = 64
      Width = 75
      Height = 25
      Caption = 'BitBtn1'
      TabOrder = 5
    end
  end
  object VectLog: TMemo
    Left = 605
    Top = 87
    Width = 329
    Height = 582
    TabOrder = 1
    Visible = False
    OnDblClick = VectLogDblClick
    OnMouseEnter = Image2MouseEnter
    OnMouseLeave = VectLogMouseLeave
    OnMouseMove = VectLogMouseMove
  end
  object checkYX: TPanel
    Left = 554
    Top = 8
    Width = 75
    Height = 15
    Caption = 'checkYX'
    Enabled = False
    TabOrder = 2
    Visible = False
  end
  object ColorDialog1: TColorDialog
    Left = 8
    Top = 96
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 56
    Top = 96
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 128
    Top = 96
  end
  object MainMenu1: TMainMenu
    Left = 312
    Top = 240
    object N121: TMenuItem
      Caption = 'File'
      object Save1: TMenuItem
        Caption = 'Save'
        ShortCut = 16467
        OnClick = SaveClick
      end
      object Load1: TMenuItem
        Caption = 'Load'
        ShortCut = 16454
        OnClick = LoadClick
      end
      object Undo1: TMenuItem
        Caption = 'Undo'
        ShortCut = 16474
        OnClick = undoClick
      end
      object New1: TMenuItem
        Caption = 'New'
        ShortCut = 16462
        OnClick = ClearClick
      end
      object SaveV1: TMenuItem
        Caption = 'SaveV'
        OnClick = SvectClick
      end
      object SaveV2: TMenuItem
        Caption = 'LoadV'
        OnClick = LvectClick
      end
    end
    object Log1: TMenuItem
      Caption = 'Log'
      ShortCut = 16460
      OnClick = Log1Click
    end
    object XandY1: TMenuItem
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 56
    Top = 152
  end
  object SaveDialog1: TSaveDialog
    Left = 56
    Top = 208
  end
end
