CREATE DATABASE [MYDB]
GO
USE [MYDB]
GO
/****** Object:  Table [dbo].[Stock]    Script Date: 2021/06/29 11:33:03 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Stock](
	[Code] [nchar](10) PRIMARY KEY,
	[Description] [ntext] NULL,
	[Barcode] [varchar](12) NULL,
	[Qty] [numeric](18, 0) NULL,
	[Price] [money] NULL
	)
GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[Transactions]    Script Date: 2021/06/29 11:33:03 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO

CREATE TABLE [dbo].[Transactions](
[TransactionNo] [int] IDENTITY(1,1) PRIMARY KEY,
[Type] [varchar](10) NULL,
[InvoiceNum] AS (format([TransactionNo],'0000#')),
[Barcode] [varchar](12) NULL,
[Qty] [int] NULL,
[Price] [money] NULL,
[Timestamp] [varchar](50) NULL,
)

GO
SET ANSI_PADDING OFF
GO

INSERT INTO [dbo].[Stock] ([Code], [Description], [Barcode], [Qty], [Price])
VALUES ('0001', 'Milk', '111111111111', 49, 30.50);
GO
INSERT INTO [dbo].[Stock] ([Code], [Description], [Barcode], [Qty], [Price])
VALUES ('0002', 'Chocolate Milk', '111111111112', 49, 45.00);
GO
INSERT INTO [dbo].[Stock] ([Code], [Description], [Barcode], [Qty], [Price])
VALUES ('0003', 'Strawberry Milk', '111111111113', 49, 42.00);
GO
INSERT INTO [dbo].[Stock] ([Code], [Description], [Barcode], [Qty], [Price])
VALUES ('0004', 'Chocolate Bar', '111311111111', 49, 12.00);
GO
INSERT INTO [dbo].[Stock] ([Code], [Description], [Barcode], [Qty], [Price])
VALUES ('0005', 'Caramel Bar', '111311111112', 49, 15.00);
GO
INSERT INTO [dbo].[Stock] ([Code], [Description], [Barcode], [Qty], [Price])
VALUES ('0006', 'White Bread', '121111111111', 49, 13.50);
GO
INSERT INTO [dbo].[Stock] ([Code], [Description], [Barcode], [Qty], [Price])
VALUES ('0007', 'Brown Bread', '121111111112', 49, 12.50);
GO
INSERT INTO [dbo].[Stock] ([Code], [Description], [Barcode], [Qty], [Price])
VALUES ('0008', 'Wholewheat Bread', '121111111113', 49, 15.50);
GO
INSERT INTO [dbo].[Stock] ([Code], [Description], [Barcode], [Qty], [Price])
VALUES ('0009', 'Dog food', '333111111111', 49, 80.00);
GO
INSERT INTO [dbo].[Stock] ([Code], [Description], [Barcode], [Qty], [Price])
VALUES ('0010', 'Cat food', '333111111112', 49, 70.00);
GO
INSERT INTO [dbo].[Stock] ([Code], [Description], [Barcode], [Qty], [Price])
VALUES ('0011', 'Pasta', '123111111111', 49, 15.00);
GO
INSERT INTO [dbo].[Stock] ([Code], [Description], [Barcode], [Qty], [Price])
VALUES ('0012', 'Rice', '321111111111', 49, 18.00);
GO