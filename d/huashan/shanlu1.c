// Room: /d/huashan/shanlu1.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
       set("short", "ɽ·");
       set("long", @LONG
����ͨ����ɽ�����õ�ɽ·������ɽ���վ�����ľ���ģ��������ӣ���ˮ
���ȣ���������ǽ��������ɽ�»�߻�͵Ĺ��������Ϸ�����С��ͨ��ɽ�ϡ�
LONG
        );
       set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"yunu",
	"southeast" : __DIR__"shanlu2",
	]));

	set("objects",([
		__DIR__"npc/monkey" : 1,
	]));

       set("outdoors", "��ɽ" );

       set("coor/x",70);
  set("coor/y",20);
   set("coor/z",60);
   setup();
}
