// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "��·����");
	set("long", @LONG
ɽ���·������խ����Щ�ط�ֻ�����˲������ӷ��ܹ�ȥ������·��ɽ��
���죬������ȫȻ��ȥ����˴˴���ʢ�ĵ����Ե���Ϊ�������ڴ˿���Զ����
Զ����������ˮ����
LONG
	);
	set("outdoors", "��Դ��");
	set("exits", ([
		"northeast" : __DIR__"xiaolu1",
		"south" : __DIR__"pubu",
	]));

	setup();
}
