/*
 * Exported with brandontools v1.0
 * Invocation command was brandontools -mode4 buzz art/buzz.png art/flames.png 
 * Time-stamp: Tuesday 11/11/2014, 22:02:54
 * 
 * Image Information
 * -----------------
 * art/buzz.png 30@30
 * art/flames.png 40@10
 * 
 * Quote/Fortune of the Day!
 * -------------------------
 * A C program is like a fast dance on a newly waxed dance floor by people carrying razors. - Waldi Ravens.
 * 
 * Don't let the past and useless detail choke your existence.
 * 
 * All bug reports / feature requests are to be sent to Brandon (brandon.whitehead@gatech.edu)
 */

const unsigned short buzz_palette[223] =
{
	0x0000,0x0400,0x0800,0x0c00,0x0821,0x0c21,0x0422,0x0c22,0x0c42,0x0043,
	0x0843,0x0c43,0x0c63,0x1063,0x0864,0x0c64,0x1084,0x1085,0x1485,0x1885,
	0x14a5,0x10a6,0x10c7,0x18c7,0x04c8,0x10e8,0x2108,0x1109,0x2529,0x110a,
	0x112a,0x212a,0x292a,0x0d2b,0x112b,0x152b,0x294b,0x316b,0x052c,0x112c,
	0x114c,0x398c,0x0d4d,0x114d,0x116d,0x1d6d,0x218d,0x35ad,0x056e,0x116e,
	0x118e,0x35ae,0x39ce,0x11af,0x21af,0x35af,0x25cf,0x29cf,0x31cf,0x35cf,
	0x3def,0x45ef,0x520f,0x1dd0,0x3df0,0x4210,0x0db1,0x11d1,0x29f1,0x3a11,
	0x4211,0x4e31,0x5631,0x5a51,0x09d2,0x0dd2,0x11f2,0x1212,0x4632,0x4a52,
	0x05d3,0x0df3,0x11f3,0x0a13,0x1a13,0x2a33,0x3233,0x3633,0x4e73,0x5273,
	0x5a73,0x0e14,0x1214,0x1614,0x1234,0x1634,0x2e34,0x4e74,0x5274,0x5294,
	0x5694,0x5a94,0x0a15,0x1215,0x1615,0x1235,0x1635,0x2655,0x3675,0x5295,
	0x4eb5,0x56b5,0x5ab5,0x0636,0x0e36,0x1636,0x1256,0x1656,0x2256,0x1276,
	0x4eb6,0x56b6,0x56d6,0x5ad6,0x5ed6,0x0a57,0x0e57,0x1657,0x0e77,0x1277,
	0x1677,0x1a77,0x1297,0x5af7,0x5ef7,0x62f7,0x6317,0x6f17,0x0e78,0x1678,
	0x1698,0x5ef8,0x5f18,0x6318,0x6b38,0x0299,0x1299,0x1699,0x0ab9,0x12b9,
	0x5719,0x6319,0x6739,0x169a,0x0eba,0x12ba,0x0eda,0x16da,0x12fa,0x673a,
	0x6b5a,0x0ebb,0x12bb,0x16bb,0x16db,0x0efb,0x12fb,0x1efb,0x6b5b,0x6f7b,
	0x737b,0x779b,0x0edc,0x12dc,0x16dc,0x16fc,0x171c,0x133c,0x6f7c,0x739c,
	0x779c,0x77bc,0x7bbc,0x12dd,0x16dd,0x02fd,0x16fd,0x171d,0x173d,0x77bd,
	0x7fdd,0x16fe,0x131e,0x171e,0x173e,0x7bde,0x001f,0x043f,0x085f,0x0c7f,
	0x109f,0x14bf,0x18df,0x211f,0x253f,0x35bf,0x39df,0x529f,0x56bf,0x5adf,
	0x5eff,0x0b1f,0x171f,0x631f,0x173f,0x1b3f,0x673f,0x135f,0x175f,0x177f,
	0x1b7f,0x7bdf,0x7fff
};

const unsigned short buzz[450] =
{
	0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,
	0xdede,0xc3de,0xdec3,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,
	0xdede,0xdede,0xdede,0xdede,0xdede,0xbdde,0x2f41,0xdea9,0xdede,0xdede,
	0xc3de,0xdede,0xdede,0xdede,0x2fa9,0xdebd,0xdede,0xdede,0xdede,0xdede,
	0x3ca0,0xdea0,0xdede,0xbdde,0xa0a9,0x418d,0x5841,0xdea9,0xdede,0xb346,
	0xde33,0xdede,0xdede,0xdede,0x98de,0xde7b,0xdede,0x79bd,0x5863,0x4f63,
	0xa01a,0xa9de,0x4158,0xdea9,0xde58,0x6f98,0xdede,0xdede,0xdede,0xbdc3,
	0xdede,0x79c3,0xa06f,0xdec3,0xdede,0x3cb3,0xdede,0xbdde,0x7941,0xde4f,
	0x40de,0xdede,0xb3de,0x4fb3,0x9f33,0xc3de,0xbd98,0xdede,0xdede,0xdede,
	0xb2de,0xde34,0xdede,0x79de,0xa01a,0x97de,0x8f88,0x6a55,0x2409,0x0179,
	0x2524,0xc361,0xdede,0xdede,0xdede,0xdede,0x34a9,0xdec3,0xdede,0x24a0,
	0xb6a8,0x9a28,0x82da,0x1405,0x0f17,0x0c0a,0x0d01,0xdeb3,0xdede,0xdede,
	0xdede,0x24b3,0xdd24,0xbede,0xa0de,0x4529,0xd6ac,0x7fd6,0x0c07,0x0f0a,
	0x0c0f,0x0a2b,0xc310,0xdede,0xdede,0xdede,0x9f63,0x3d86,0x5538,0xde70,
	0x4290,0x68d6,0xda8a,0x0719,0x0f10,0x050f,0x9d52,0x5906,0xdede,0xdede,
	0xdede,0x29de,0x7c4e,0xb944,0x5a51,0x7689,0x3ad3,0x714f,0x0fa6,0x0d05,
	0x030b,0xdc5d,0x3372,0xdede,0xdede,0x86de,0x2e56,0xdeb4,0x504f,0x72d7,
	0x1132,0x75b0,0x3d48,0xa577,0x0f22,0x310f,0xbac1,0x51bf,0xdebd,0xdede,
	0x7d63,0x66da,0xbd47,0x363d,0xd6da,0x0fd4,0x9e10,0x6553,0x543e,0xbad9,
	0xd4a4,0xb8ba,0x7ebf,0xde60,0xdede,0xa245,0xc0d7,0x6427,0x1cb3,0xbb21,
	0x0faf,0x0d05,0x9484,0x4939,0xad2d,0xb8d6,0xb8b8,0x8bbf,0xb34a,0xdede,
	0x807c,0x9a8a,0xc35e,0x0440,0x1905,0x0b1e,0x0b10,0x3505,0x95b1,0x283f,
	0xd48b,0xb8b8,0x99c1,0x8e67,0xdede,0x85de,0x9886,0x96bd,0x0550,0x0810,
	0x0f08,0x0f0f,0x050f,0x7415,0xc2db,0x5d4d,0xbfd4,0xa3bf,0xa04b,0xdede,
	0xdede,0xdede,0x3087,0x16da,0x0d03,0x0f0f,0x0f0f,0x0f0f,0x0204,0x5419,
	0x5ca7,0xa12a,0xb7d6,0xde2d,0xdede,0xdede,0xbdde,0x2c01,0xaeda,0x0c22,
	0x0f0d,0x0c0c,0x110a,0x1f20,0x2369,0x8e25,0x7ab5,0x5b6b,0xde8f,0xdede,
	0xdede,0x7bde,0x0d01,0xda93,0xbcda,0x124d,0xa07b,0xbda9,0xa0de,0xad26,
	0x4752,0xdec3,0xa9c3,0xdede,0xdede,0xdede,0xa0de,0x0d06,0x4c0f,0x5d84,
	0x250e,0xdede,0xdede,0xdede,0xac3b,0xab83,0xde6d,0xdede,0xdede,0xdede,
	0xdede,0xc3de,0x0710,0x050d,0x0307,0x3a02,0xdede,0xdede,0xdede,0x71a0,
	0x5992,0xde98,0xdede,0xdede,0xdede,0xdede,0x98de,0x1d81,0x0507,0x0c05,
	0x9c4c,0xde9f,0xdede,0xdede,0x78de,0x6257,0xdede,0xdede,0xdede,0xdede,
	0xdede,0xc3de,0xd95f,0x688c,0xa473,0xa2db,0xdeaa,0xdede,0xdede,0xdede,
	0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0x43aa,0xdabc,0xd6da,
	0x199b,0xdebd,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,
	0xdede,0xdede,0xb3de,0x210e,0x1b2b,0x040b,0xde8f,0xdede,0xdede,0xdede,
	0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0x0186,0x0702,
	0x1305,0xdec3,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,
	0xdede,0xdede,0xdede,0xa8de,0x1033,0x4418,0xdede,0xdede,0xdede,0xdede,
	0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xbdde,
	0x916c,0xdea8,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,
	0xdede,0xdede,0xdede,0xdede,0xdede,0x6ede,0xc32a,0xdede,0xdede,0xdede,
	0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,
	0xdede,0x4ea0,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede,0xdede
};

const unsigned short flames[200] =
{
	0x0000,0x0000,0xc4d0,0xc4c4,0xc4c4,0x00c4,0x0000,0x0000,0x0000,0xd800,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0xc4cf,0xc4c4,0xc4c4,0xc4c4,0x00c4,0x0000,0x0000,0xc500,0xc4c4,
	0x00c4,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0xc400,0xc4c4,0xc4c4,0xc4c4,0xc4c4,0x00c4,0x0000,0xc4cd,0xc4c4,0xc4c4,
	0x00c4,0x0000,0x0000,0x0000,0xd000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0xc4c4,0xc4c4,0xc4c4,0xc4c4,0xc4c4,0x00c4,0xc500,0xc4c4,0xc4c4,0xc4c4,
	0x00c4,0x0000,0x0000,0xcb00,0xc4c4,0x00c5,0x0000,0x0000,0xce00,0xc8c4,
	0xc4c4,0xc4c4,0xc4c4,0xc4c4,0xc4c4,0x00c4,0xc4ca,0xc4c4,0xc4c4,0xc4c8,
	0x00c4,0x0000,0xcb00,0xc4c4,0xc4c4,0x00c4,0x0000,0x0000,0xc4c7,0xc4c4,
	0xc4c4,0xc4c4,0xc4c4,0xc4c4,0xc4c4,0x00c4,0xc400,0xc4c4,0xc4c4,0xc4c4,
	0x00c4,0x0000,0xc4c9,0xc4c4,0xc4c4,0x00c4,0x0000,0x0000,0xc4c4,0xc4c4,
	0xc400,0xc4c4,0xc4c4,0xc4c4,0xc4c4,0x00c4,0x0000,0xc4c4,0xc4c4,0xc4c4,
	0x00c4,0x0000,0xc4c7,0xc4c4,0xc4c4,0x00c4,0x0000,0x0000,0xc4d1,0xc4c4,
	0x0000,0xc4c4,0xc4c4,0xc4c4,0xc4c4,0x00c4,0x0000,0xc4c4,0xc4c4,0xc4c4,
	0x00c4,0x0000,0xc800,0xc4c4,0xc4c4,0x00ca,0x0000,0x0000,0xd100,0xc4c4,
	0x0000,0xd500,0xc4c4,0xc4c4,0xc4c4,0x00c4,0x0000,0x3700,0xc4c8,0xc4c4,
	0x00cf,0x0000,0x0000,0xd200,0xc7c6,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0xd800,0xc4c6,0xc4c4,0x00cc,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
};

