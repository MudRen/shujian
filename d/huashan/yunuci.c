// Room: /d/huashan/yunuci.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "��Ů��");
	set("long", @LONG
��Ů���﹩��ĵ�������λ��Ů������಻ͬ��˵�����������ܿ�����ֻ
һ������ʯ�����д�ʯ����һ�����ݣ�������ˮ��̣���˵����������Ů
��ϴ���裬��ˮ���겻�ɡ�����������һ����̳���ǻ�ɽ���������������챣
��һ��ˮ���ĵط���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"yunu",
	       "enter" : __DIR__"jitan",
	]));
        set("resource/water", 1);
        set("no_clean_up", 0);

        set("outdoors", "��ɽ" );
        set("coor/x",80);
  set("coor/y",30);
   set("coor/z",60);
   setup();
}
