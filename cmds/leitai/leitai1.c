#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"������"NOR);
    set("long", "�������齣������ı�����̨�������˵�����кܶ��������ʿ�������
���ա���̨������������У���̨֮����һ�������ܣ���������������
���Դӱ���������ȡ��Ҫ�������ͻ��ߡ�����̨���������һ�������(paizi)
������̨��һ�Ƿ���һ����ʦ��֪(sign)��\n");

	set("no_death", 1);
	set("no_get_from", 1);
	set("no_sleep_room", 1);
	set("no_save", 1);
	set("no_fight", 1);
	set("dest_room", "/d/wizard/lt1");

	set("objects", ([
		__DIR__"npc_leitai" : 1,
	]));

	set("item_desc", ([
		"sign" : "\n����֮�˱������������ϵ���ʦ��( login )�İ취�Ž�����̨�����ǳ���
�Զ����롣��˫����׼����( ok )���Ժ�ʼ���䣬������ʦ�±�������( biwu )��
��ʦ����������˳�( tui )��̨����������̨��Ϣ( xinxi )��\n\n",
	     "paizi" : "\n����֮�˿��Դ���Ʒ������ȡ��Ʒ��׼�����˺���� OK ��
���Ҫ������������� LEAVE ��\n\n",
	]));

	setup();

}
#include "leitai.h";
