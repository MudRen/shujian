// Room: /u/swl/songshan/gsfxia.c

inherit ROOM;

void create()
{
	set("short", "��ʤ����");
	set("long", @LONG
����һ�̣�������ˮ�����ף��ͱ�����������ֱ��������˫�ٲ�к��
������������Ծ���ݡ����ٲ�֮��������ȥ�����������Ĺ�ʤ�塣�ٲ�
����֮��ΰ���˸е�һ�־�η֮�顣
LONG);
	set("exits", ([
            "southeast" : __DIR__"shanlu2",
            "westup" : __DIR__"guanshengfeng",
        ]));
        set("objects", ([ 
            __DIR__"npc/ssdizi" : 2,
        ]));
        set("outdoors", "��ɽ");
	set("coor/x",60);
  set("coor/y",160);
   set("coor/z",60);
   setup();
}
