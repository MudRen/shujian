// /u/beyond/mr/xiaozhou7.c
// this is made by beyond
// update 1997.6.20
inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ���ϴ����ֳֳ���ݣ����ڴ�β
�����س��Ŵ����������ȥ�������ϵ�������ɫʹ�㸡����ƪ��
LONG
	);
	set("outdoors", "Ľ��");

        set("no_fight",1);

	setup();
}

void run(object ob)
{
	if (!ob) return;
	if (environment(ob) == this_object()) {
		tell_object(ob,"\nС��ʻ��һƬһ���޼ʵĺɻ�����һ����ȥ, ������Ҷ, ��Ҷ, «έ, ���ף�\n"
				"����һģһ��, ��֮��Ҷ, ��Ҷ��ˮ��Ư��, ��ʱһ�����, �㼴�仯�ٶˣ�\n"
				"����˿̼ǵ��������, ��ʱ������ȫȻ��ͬ��\n\n");
		ob->move(__DIR__"zhou8", 1);
	}
}

void init()
{
	object ob = this_player();
	call_out("run", 5, ob);
}
