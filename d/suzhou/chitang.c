#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"����"NOR);
	set("long", @LONG
һ�س�ˮӳ�����������С������Ȼˮ�У����۵�ʯ���ϼ������ٻ��
�ض�����Կ�����Ϫ¥����¥�����ص�С������ӳ�ڻ�ľɽʯ֮�䡣������
ɽ���䣬�������������գ������ڡ���ľ����������������㣬������Ƣ����
�£�ˮ��������ʯ���أ��㲻��Ϊ�˾�����̾���ѡ�
LONG	);
	set("exits", ([ 
		"northeast" : __DIR__"gumujiaohe",
	]));
	set("outdoors", "����" );
	set("no_clean_up", 0);
	set("incity",1);
	setup();
}
