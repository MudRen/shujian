// by Xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "������ԭ");
	set("long", @LONG
�ƺ���һ�����н�������ԭ�п���������СϪ���д�����ɳ����ƺӣ���
��ǧ�����֡�����֮���һ���ƽ�ؽ���̨ܫ���ƺ����ɹŸ�ԭ�ϱ������ʣ�
��̫��ɽ������������תͷ���£��γɽ��µķֽ硣
LONG );
	set("exits", ([
		"northwest" : "/d/changan/road2",
		"southeast" : __DIR__"huanghe_1",
	]));
        set("objects",([
                NPC_D("tiao-fu") : 2,
        ]));
	set("outdoors", "�ƺ�");
	setup();
}
