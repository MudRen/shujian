// /u/beyond/mr/xiaozhou8.c
// this is made by beyond
// update 1997.6.20
inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ������������ֳֳ���ݣ�
���ڴ�β�����س��Ŵ���
LONG
	);
	set("outdoors", "Ľ��");
        set("no_fight",1);

	setup();
}

void run(object ob)
{
	if(!ob) return;
	if (environment(ob) == this_object()){
		ob->move(__DIR__"zhou9", 1);
	}
}

void init()
{
	object ob = this_player();
	tell_object(ob, "\nС���ںɻ����л�������,��һ����㿴������С���������ˡ�\n\n");
	call_out("run", 5, ob);
}
