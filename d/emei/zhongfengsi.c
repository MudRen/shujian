// Room: /d/emei/zhongfengsi.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "�з���" NOR);
	set("long", @LONG
�з����ڰ��Ʒ��£�ʼ���ڽ�����ԭΪ���ۡ���˵���ڵĵ���ÿ��������
���ն������ɽ��һ����������Ϊ�������ɡ������и�����������������ʦ��
ɱ��������������ʿ��ʼ֪�ϵ����м����ѣ���Ը���ŷ�̣��Ӵ˸Ĺ�Ϊ�¡�
���������ɵ������󣬶�������ˮ�֡�
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([
  "northwest" : __DIR__"qingyinge",
  "eastdown" : __DIR__"shenshuian",
]));
	set("no_clean_up", 0);

	setup();
}
