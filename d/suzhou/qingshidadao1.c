inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�
long);
set("outdoors", "suzhou");
set("exits",([
"north" : __DIR__"qingshidadao",
"south" : __DIR__"qingshidadao2",
]));
set("coor/x",120);
  set("coor/y",-310);
   set("coor/z",0);
   setup();
}