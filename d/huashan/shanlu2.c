// Room: /d/huashan/shanlu2.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����ͨ����ɽ�����õ�ɽ·������ɽ���վ�����ľ���ģ��������ӣ���ˮ
���ȣ������Ѿ��������οͣ�ż���������ֻҰ�޳�û��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"xiaoxi",
	"northwest" : __DIR__"shanlu1",
	"southup" : __DIR__"taijie",
	]));

	set("objects", ([ 
		__DIR__"npc/monkey" : 1,
	]));

        set("outdoors", "��ɽ" );

        set("coor/x",80);
  set("coor/y",10);
   set("coor/z",60);
   setup();
}
