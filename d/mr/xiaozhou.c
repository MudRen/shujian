// /u/beyond/mr/xiaozhou.c 
// this is made by beyond
// update 1997.6.20
inherit ROOM;
void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
�������ӵĻ�����е�����һ��С���ϣ����ϵĴ������˵��������
�ˡ���������͵���٢��ɽׯȥ��
LONG
	);
	set("outdoors", "Ľ��");
        set("no_fight",1);
	setup();
}

void run(object ob)
{
	if (!ob)
		return;

	if (environment(ob) == this_object()){
		ob->move(__DIR__"xiaozhou1", 1);
		tell_object(ob, "\n����Ѵ�ʻ����һƬһ���޼ʵĺɻ�����һ����ȥ, ������Ҷ, ��Ҷ, «έ, \n"
			"����, ����һģһ��, ��֮��Ҷ, ��Ҷ��ˮ��Ư��, ��ʱһ�����, �㼴�仯\n"
			"�ٶ�, ����˿̼ǵ��������, ��ʱ������ȫȻ��ͬ��\n\n");
	}
}

void init()
{
	object ob = this_player();
	call_out("run", 5, ob);
}
