// /u/beyond/mr/zhou.c
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
	set("no_fight",1);
	set("outdoors", "Ľ��");

	setup();
}

void run(object ob)
{
	if ( !ob) return;
	if (environment(ob) == this_object()){
		tell_object(ob,"\n����Ѵ�ʻ����һƬһ���޼ʵĺɻ�����һ����ȥ, ������Ҷ, ��Ҷ, «έ, \n"
			"����, ����һģһ��, ��֮��Ҷ, ��Ҷ��ˮ��Ư��, ��ʱһ�����, �㼴�仯\n"
			"�ٶ�, ����˿̼ǵ��������, ��ʱ������ȫȻ��ͬ��\n\n");
		ob->move(__DIR__"zhou1", 1);
	}
}

void init()
{
	object ob = this_player();
	call_out("run",  5, ob);
}
