// Room: /d/emei/jinding.c ������ ��

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "��" NOR);
	set("long", @LONG
����Ƕ���ɽ��������ˡ��˷�������أ������Ʊ���������׳����
���������������ڤ���쿪���ʴ��ɻ����������Ͻ𶥣���Ұ��Ȼ���ʣ���
���£�����Ⱥ��ӿ�̵��䣬������˿���������Զ���������ѩɽ��ب��ʣ�
����ɽֱ���񷡣
LONG
	);
	set("outdoors", "����ɽ");
	set("exits", ([
		"northdown" : __DIR__"wanxingan",
		"southwest" : __DIR__"woyunan",
		"southup" : __DIR__"huazangan",
	]));

	set("valid_startroom",1);

	setup();

}
