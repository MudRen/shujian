inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long",@long
������ɽ����״����֥�ľ�ʯ����������ɽ������ɽ��ͦ����������ʯ
��ᾣ���������⹬�ż������С����е�һ�塱��������
long);
set("outdoors", "suzhou");
set("objects",([
__DIR__"obj/xiao-shuzhi" : 1,
__DIR__"obj/da-shitou" : 1,
]));
set("exits",([
"south" : __DIR__"qingshidadao",
"eastup" : __DIR__"yingxiaoting",
"northwest" : __DIR__"tianpingshan",
]));
set("coor/x",120);
  set("coor/y",-290);
   set("coor/z",0);
   setup();
}
