// Room: /u/beyond/ningbo/baoguosi.c ������
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"������"NOR);
	set("long", @LONG
���߽��������ڣ���������ڵ�ȫ���ṹ����һ�����ӣ���ȫ���Ŷ���֮
�������֧�š��컨���ϲ����������������ο��微���㲻��Ϊ�ܹ��ɽ��ľ�
տ�������۷���
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"shilu",
	]));
	setup();
}
