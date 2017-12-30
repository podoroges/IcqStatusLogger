object FMain: TFMain
  Left = 192
  Top = 107
  BorderStyle = bsDialog
  Caption = 'Icq Status Logger'
  ClientHeight = 348
  ClientWidth = 688
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 688
    Height = 49
    Align = alTop
    Caption = 'Icq'
    TabOrder = 0
    object Label1: TLabel
      Left = 192
      Top = 15
      Width = 494
      Height = 32
      Align = alRight
      Alignment = taCenter
      AutoSize = False
      Caption = 'Label1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Layout = tlCenter
    end
    object Edit1: TEdit
      Left = 16
      Top = 16
      Width = 145
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Fixedsys'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = 'Edit1'
      OnChange = Edit1Change
    end
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 49
    Width = 688
    Height = 105
    Align = alTop
    Caption = 'Graph'
    TabOrder = 1
    object pb: TPaintBox
      Left = 2
      Top = 15
      Width = 684
      Height = 88
      Align = alClient
      OnPaint = pbPaint
    end
  end
  object GroupBox3: TGroupBox
    Left = 0
    Top = 154
    Width = 688
    Height = 194
    Align = alClient
    Caption = 'Log'
    TabOrder = 2
    object Memo1: TMemo
      Left = 2
      Top = 15
      Width = 684
      Height = 177
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Fixedsys'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
  end
  object Timer1: TTimer
    Interval = 5000
    OnTimer = Timer1Timer
    Left = 448
    Top = 56
  end
end
