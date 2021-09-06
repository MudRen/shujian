#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��;��");
        set("long", @LONG
����һ����������;��
LONG);
	set("no_fight", 1);
	set("no_get_from", 1);
	set("no_sleep_room", 1);
	set("no_death", 1);
	setup();
}

void init()
{
	object me = this_player();
	call_out("wait", (random(20)+10)+30, me);
	call_out("do_bird", 20, me);
	add_action("do_action", "");
}

int do_action(string arg)
{
	string action = query_verb();
	switch (action) {
		case "dazuo":
		case "look":
		case "l":
		case "exercise":
		case "lian":
		case "tuna":
		case "quit":
		case "save":
		case "practice":
			write("����һ����������;����֪ʲôʱ��ſ������ꡣ\n");
			return 1;
	}
	return 0;
}

void do_bird()
{
	switch(random(3)) {
		case 0 : write(HIW"\nһ��΢�紵��������һ˿�����Ļ����һ�ɷҷ�������ζ��\n\n"NOR);
		break;
	case 1 : write(GRN"\n�Ӳ�Զ����ˮ���ɵĺ�����Ʈ��һ��������ת�ĸ�����������Ů���ں͸���Ц�����۲�����\n\n"NOR);
		this_player()->add("potential", 1);
		break;
	case 2 : write(HIY"\nֻ����������Ѫ���Ϧ��֮�ԣ�����һƬ�����ɵ�����
		�����в�ס����ɫ�Ĺ�â��������ɫ֮������ʵ������ƽ����δ�á�\n\n"NOR);
		this_player()->add("combat_exp", 5);
		break;
	}
}

void wait()
{
	object me;
	me = this_player();
	tell_object(me, "�������ϼ�����ߣ���֪�������ѵ�����Ŀ�ĵء�\n\n");
	if(me->query_temp("go_hj")) {
		me->move("/d/hj/majiu");
		tell_object(me, CYN"��ϼ�͸����㣺����ؽ���������˵�⸽���и�ʲô���أ���û�����ҵ���\n\n"NOR);
		me->delete_temp("go_hj");
	}
	if(me->query_temp("go_xx")) {
		me->move("/d/xingxiu/xxh");
		tell_object(me, CYN"��ϼ�͸����㣺������������޺��ˣ���С�ĵ㣬�������ɵĶ���ץס�˿ɲ��Ǻ���ģ�\n\n"NOR);
		me->delete_temp("go_xx");
	}
	if(me->query_temp("go_yili")) {
		me->move("/d/xingxiu/yili2");
		tell_object(me, CYN"��ϼ�͸����㣺��������ǵ���������ɶ�Ҫ����������ζ�Ĺ��ܹϡ�\n\n"NOR);
		me->delete_temp("go_yili");
	}
	if(me->query_temp("go_sl")) {
		me->move("/d/shaolin/ting");
		tell_object(me, CYN"��ϼ�͸����㣺�����������ɽ�������ˡ�����ĺ�����������ǹŪ���ģ�����\n\n"NOR);
		me->delete_temp("go_sl");
	}
	if(me->query_temp("go_wd")) {
		me->move("/d/wudang/yuzhengong");
		tell_object(me, CYN"��ϼ�͸����㣺�䵱ɽ�����������������Ͼ����䵱�������ˣ����Լ��ϰɡ�\n\n"NOR);
		me->delete_temp("go_wd");
	}
	if(me->query_temp("go_kl")) {
		me->move("/d/kunlun/shanmen");
		tell_object(me, CYN"��ϼ�͸����㣺��ֻ����������ɽ�����ˣ�����������Լ��߰ɡ�\n\n"NOR);
		me->delete_temp("go_kl");
	}
	if(me->query_temp("go_yz")) {
		me->move("/d/city/kedian");
		tell_object(me, CYN"��ϼ�͸����㣺�������������������������������ô��ô�������ݶ��Ҳ�����\n\n"NOR);
		me->delete_temp("go_yz");
	}
	if(me->query_temp("go_dali")) {
		me->move("/d/dali/damen");
		tell_object(me, CYN"��ϼ�͸����㣺�Ͻ������������ǵ�����������紾�ӣ���ͷ�������ɡ�\n\n"NOR);
		me->delete_temp("go_dali");
	}
	if(me->query_temp("go_tzb")) {
		me->move("/d/tiezhang/shanjiao");
		tell_object(me, CYN"��ϼ�͸����㣺�������ָɽ�ˡ�����ȥ��ҪС�ĵ㣬���ư���˿����ˣ�\n\n"NOR);
		me->delete_temp("go_tzb");
	}
	if(me->query_temp("go_thd")) {
		me->move("/d/thd/haibin");
		tell_object(me, CYN"��ϼ�͸����㣺ֻ�ܴ��㵽�����ˣ�Ҫȥ�һ���������������������\n\n"NOR);
		me->delete_temp("go_thd");
	}
	if(me->query_temp("go_mj")) {
		me->move("/d/mingjiao/shanting");
		tell_object(me, CYN"��ϼ�͸����㣺ǰ��������̹��������ҿɲ�����ȥ�����Լ�ȥ�ɣ�\n\n"NOR);
		me->delete_temp("go_mj");
	}
	if(me->query_temp("go_sz")) {
		me->move("/d/suzhou/majiu");
		tell_object(me, CYN"��ϼ�͸����㣺���������ݳ��ˣ����ó�������ӻ��ǵ�һ�����ɣ�����\n\n"NOR);
		me->delete_temp("go_sz");
	}
	if(me->query_temp("go_zns")) {
		me->move("/d/gumu/shanlu1");
		tell_object(me, CYN"��ϼ�͸����㣺ǰ����ɽ��������ɽ��������ȥ����ȫ����������ˡ�\n\n"NOR);
		me->delete_temp("go_zns");
	}
	if(me->query_temp("go_hz")) {
		me->move("/d/hz/tianxianglou");
		tell_object(me, CYN"��ϼ�͸����㣺���㵽�����ˣ�����������ô�������������ã������պ������治�٣�\n\n"NOR);
		me->delete_temp("go_zns");
	}
	tell_room(environment(me), me->name()+"����ϼ�ͷ糾���͵����˹�����\n" NOR,
	({ me }));
	tell_object(me, "��ϼ���ֲ�֪�ߵ�����ȥ�ˡ�\n");
}