//hhyang-2.c ����
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", HIR"����"NOR);
	set("long", @LONG
ֻ�����������������ܰ�������١����ȡ���𡢺콶����������ʢ��
���㻨��Ժǽ���ֹ��˼�ľ�����������������飬����ܰ��Ϯ�ˣ������԰��
԰�����Ϸ��ż�����ź����ϡ����ˡ����ʹ��������϶���һ�����ȣ�������
������Ϣ�ĵط���
LONG
	);

	set("exits", ([
"west" : __DIR__"hhyuan-1",
]));

	set("no_clean_up", 0);
        set("outdoors", "tiezhang");

	set("coor/x",-320);
  set("coor/y",-230);
   set("coor/z",10);
   setup();
}
