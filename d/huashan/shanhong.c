// Room: /d/huashan/shahong.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "ɽ���ٲ�");
        set("long", @LONG
ת��һ��ɽϿ��ˮ�����������ֻ��ɽ���һ�������Ƶ��ٲ���к���£�
����һ��Ϫ������ʤ�������ļ��쳣��ˮ��Ю����֦ʯ�飬ת�۱����ò�֪
ȥ��Ϫ��(river)��������һ���ʯ(stone)��ˮ���ɽ����Ĺ�ˮ�����ɣ�
εΪ��ۡ���ɽ���Ƶ����ң��������о��⣬���Ǳ������ĺá�
LONG
        );
       set("exits", ([ 
        "southwest" : __DIR__"shaluo",
	]));
	set("item_desc", ([
        "river" : "ɽˮ���ٲ�����Ϫ���������쳣�ļ���\n",
        "stone" : "һ��޴����ʯ���������ر�ɽ���͸����ɡ�\n",
	]));
       set("outdoors", "��ɽ" );

       set("coor/x",60);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}