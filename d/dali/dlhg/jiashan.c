// By River 98/12
inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "��ɽʯ");
	set("long", @LONG
��ӭ��ͻ������Ĵ�����ɽʯ��������Ⱥ�Ƹ�ʽʯ�飬�����������з���Ϥ
����ס����һ�껨ľҲ�ޣ�ֻ�������ݣ�����ǣ�ٵģ����������ģ���ɽ�ۣ�
��ʯ϶�������������������̽ף�������ƮƮ����������������ʵ�絤ɰ��
������ζ����𥣬�ǻ���֮�ɱȡ�
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"chitang",                
	]));
	set("outdoors", "����");
	set("coor/x",-330);
  set("coor/y",-380);
   set("coor/z",-20);
   setup();
}
