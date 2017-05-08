object WindowTree: TWindowTree
  Left = 0
  Top = 0
  Caption = 'WindowTree'
  ClientHeight = 499
  ClientWidth = 526
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Name: TLabel
    Left = 240
    Top = 173
    Width = 73
    Height = 13
    Caption = #1048#1084#1103' '#1088#1072#1073#1086#1095#1077#1075#1086':'
  end
  object ID: TLabel
    Left = 240
    Top = 219
    Width = 85
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1087#1088#1086#1087#1091#1089#1082#1072':'
  end
  object Label1: TLabel
    Left = 398
    Top = 171
    Width = 85
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1087#1088#1086#1087#1091#1089#1082#1072':'
  end
  object StringGrid: TStringGrid
    Left = 8
    Top = 8
    Width = 217
    Height = 249
    BiDiMode = bdLeftToRight
    ColCount = 2
    DefaultColWidth = 100
    RowCount = 9
    FixedRows = 0
    ParentBiDiMode = False
    TabOrder = 0
    ColWidths = (
      100
      100)
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24
      24)
  end
  object Memo: TMemo
    Left = 240
    Top = 8
    Width = 263
    Height = 145
    TabOrder = 1
  end
  object TreeView: TTreeView
    Left = 8
    Top = 303
    Width = 360
    Height = 188
    Indent = 19
    TabOrder = 2
  end
  object AddAll: TButton
    Left = 64
    Top = 263
    Width = 105
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1076#1077#1088#1077#1074#1086
    TabOrder = 3
    OnClick = AddAllClick
  end
  object NewName: TEdit
    Left = 240
    Top = 192
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object NewId: TEdit
    Left = 240
    Top = 232
    Width = 121
    Height = 21
    NumbersOnly = True
    TabOrder = 5
  end
  object Add: TButton
    Left = 272
    Top = 259
    Width = 89
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 6
    OnClick = AddClick
  end
  object SearchId: TEdit
    Left = 398
    Top = 190
    Width = 105
    Height = 21
    TabOrder = 7
  end
  object Search: TButton
    Left = 398
    Top = 217
    Width = 105
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    TabOrder = 8
    OnClick = SearchClick
  end
  object Delete: TButton
    Left = 398
    Top = 248
    Width = 105
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 9
    OnClick = DeleteClick
  end
  object Show: TButton
    Left = 400
    Top = 335
    Width = 103
    Height = 25
    Caption = #1055#1086#1082#1072#1079#1072#1090#1100
    TabOrder = 10
    OnClick = ShowClick
  end
  object Postorder: TButton
    Left = 400
    Top = 459
    Width = 103
    Height = 25
    Caption = #1054#1073#1088#1072#1090#1085#1099#1081' '#1086#1073#1093#1086#1076
    TabOrder = 11
    OnClick = PostorderClick
  end
  object Inorder: TButton
    Left = 400
    Top = 428
    Width = 103
    Height = 25
    Caption = #1042' '#1074#1086#1079#1088#1072#1089#1090#1072#1085#1080#1080
    TabOrder = 12
    OnClick = InorderClick
  end
  object Preorder: TButton
    Left = 400
    Top = 397
    Width = 103
    Height = 25
    Caption = #1055#1088#1103#1084#1086#1081' '#1086#1073#1093#1086#1076
    TabOrder = 13
    OnClick = PreorderClick
  end
  object Balance: TButton
    Left = 400
    Top = 366
    Width = 103
    Height = 25
    Caption = #1057#1073#1072#1083#1072#1085#1089#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 14
    OnClick = BalanceClick
  end
  object DeleteNode: TButton
    Left = 398
    Top = 279
    Width = 105
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1077#1088#1096#1080#1085#1091
    TabOrder = 15
    OnClick = DeleteNodeClick
  end
end
