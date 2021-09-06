// jinhe.c ���
// By River@SJ For qianzhu-wandushou 2002.11
// By Spiderii@ty �����츳
inherit ITEM;
#include <ansi.h>

string do_look();
void create()
{
    set_name(HIY"���"NOR, ({ "jin he", "jin", "goldbox", "he" }));
	set_weight(2500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("value", 2500);
		set("unique", 1);
		set("no_give", 1);
		set("no_get", 1);
		set("treasure",1);
		set("material", "gold");
	}
	set("xiulian", 50 );
	set("long", (: do_look :));
	setup();
}

void init()
{
	add_action("do_open", "open");
	if (environment() == this_player()) {
		add_action("do_xiulian", "xiulian");
		add_action("do_zhua", ({"zhua", "dai"}));
	}
}

string do_look()
{
	string str;
	int i;
	i = query("xiulian");

	str = "������ֻĴָ��С��֩�����������֩�뱳�ϻ��ư�쵣�������Ŀ��\n";
	if ( i <= 32 )
		str = "������ֻĴָ��С��֩�����������֩�뱳�ϻ����Ѳ����ԣ��ںڷ�����\n";
	if ( i <= 15 )
		str = "������ֻĴָ��С��֩�����������֩�뱳���ѳ��ֻҰ�֮ɫ��\n";
	if ( i < 1 )
		str = "����֩����Ȼ��ȥ������տ���Ҳ��\n";
	return str;
}

int do_open(string arg)
{
	object me = this_player();

	if (!id(arg)) 
		return notify_fail("��Ҫ��ʲô����\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( query("xiulian") < 1)
		message_vision("$N�򿪺иǣ�ֻ������տ���Ҳ����˳�ֺ����ˡ�\n", me);
	else {
		message_vision(HIY"$N�򿪺иǣ�ֻ��������ֻĴָ��С��֩�����������\n"NOR, me);
		set("open", 1);
	}
	return 1;
}

int do_xiulian()
{
	object me= this_player();

	if (!query("open"))
		return notify_fail("�㻹û�򿪺иǣ�����ʲô����\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( me->query("gender") != "Ů��")
		return notify_fail("��һ������ү�ǣ���������𰡣�\n");

	if ( !me->query("quest/qianzhu/pass"))
		return notify_fail("������ô�õ���еİ���");

	if ( me->query_temp("weapon"))
		return notify_fail("���ֳ���������ô����ǧ�����ְ���\n");

	if ( me->query("neili") < 3000 )
		return notify_fail("����������������ѵֵ�֩��Ķ��ԡ�\n");

//        if ( me->query_per() < 2 )
//           return notify_fail("���Ѿ��������ܱ��ϳ����˵�ģ���ˣ��������ʵ����Щ��ò���������ɡ�\n");

	if ( me->query_temp("xiulian_qzs"))
		return notify_fail("��ո�����ǧ��������ϣ�������ЪϢһ��ɡ�\n");

	if (environment(me)->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (environment(me)->query("pending"))
		return notify_fail("�˵ز���������\n");

	if (environment(me)->query("sleep_room"))
		return notify_fail("���Ҳ�����������Ӱ�������Ϣ��\n");
 
	if (environment(me)->query("no_fight"))
		return notify_fail("�˵ز���������\n");

	me->start_busy(15);

	tell_object(me, HIR"\n����ϥ���£�����һ����ڹ�����˫������ʳָ������У�ֻ�����е�һ�Ի�\n"+
			     "�������������ֱ�ҧס��������ָͷ����������һ������˫����΢������Ǳ��\n"+
			     "�ڹ����붾�࿹��������ȡ����ָ�ϵ�ѪҺΪʳ��������ָ��Ѫ����ת��Ҳ��\n"+
			     "�˻������ڶ�Һ�������Լ�Ѫ�С�\n"NOR);

	tell_room(environment(me), HIR + me->name() + "��ϥ���£�������һ������˫����΢������Ǳ���ڹ����붾�࿹��\n"NOR, ({ me }));

	call_out("pass_xiulian", 10 + random(5), me);
	return 1;
}

void pass_xiulian(object me)
{
	if (me) {
		tell_object(me, HIB"\n������ׯ������֮�ݣ�ͬʱü�ĺ�����̫��Ѩ�ϵ�����������һ�������ҧ��\n"+
				"���أ���������ʹ����\n"NOR);
		call_out("finish_xiulian", 10 + random(5), me);
	}
	return;
}

int finish_xiulian(object me)
{
	int improve, i, lv;
	string str;

	if ( !me) return 0;

	improve = me->query_int(1) * 5;
	improve += random(improve);
	i = query("xiulian");
       lv = me->query("max_pot")-100;
	i --;
	if ( i < 1) {
		str = "���еĶ�Һ����������ָ֮����ȥ�����Զ�������˳�ֺ����˺иǡ�\n";
		delete("open");
	}
	else
		str = "ֱ��������Ѫ�������͵ú�Բ�����ƣ���ŵ��ں��У�����˯ȥ��\n";

	set("xiulian", i);
	tell_object(me, YEL"\n�ٹ�һ�ᣬ��Ǽ�������ϸϸ��һ�������飬�⹦�����˼��а��ʱ����˫��\n" + str +NOR);

	tell_room(environment(me), HIB + me->name() + "���˹����ã����Ϻ������ˣ�����Ѫɫ��һ�������˳�����\n"NOR, ({ me }));
        //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲��������ǧ�����ֵľ������ڡ�\n"NOR);
            me->set_skill("qianzhu-wandushou",lv);
            }

	me->improve_skill("qianzhu-wandushou", improve);
	me->add("shen", - improve);
	me->add("neili", -( 150 + me->query_skill("qianzhu-wandushou", 1)));
	me->set_temp("xiulian_qzs", 1);
	call_out("delete_busy", 5 , me);
	me->start_busy(-1);
	return 1;
}

void delete_busy(object me)
{
	if ( me ) me->delete_temp("xiulian_qzs");
}

int do_zhua(string arg)
{
	object me = this_player();
	object where = environment(me);
	int skill, busy = 5 + random(5);

	if ( !me->query("quest/qianzhu/pass")) return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( ! arg || arg != "zhizhu")
		return notify_fail("��Ҫץʲô����\n");

	if ( query("xiulian") > 0 )
		return notify_fail("����е�֩�뻹û���أ������Űɡ�\n");

	if ( where->query("short") != "���޺�")
		return notify_fail("�������︽��û�к��ʵ�֩�����ץ����\n");

	if ( ! present("fire", me))
		return notify_fail("��û�л��ۣ��������\n");

	if ( ! present("liu huang", me))
		return notify_fail("��û������֮����ǣ��������\n");

	skill = me->query_skill("qianzhu-wandushou", 1);
	skill /= 15;

	me->start_busy(busy+1);
	message_vision(HIY"\n$N�����������һС�飬���ڵ��ϣ��û��۵�ȼ������������\n"NOR, me);
	call_out("zhua_finish", busy*2-1, me, skill);
	return 1;
}

void zhua_finish(object me, int i)
{
	if ( me ) {
		if ( !random(3)) {
			set("xiulian", i + 40);
			message_vision(HIC"\n�����òݴ���ɪɪ���죬�̲�������ζ���$N����ǰһ����ԭ������ֻ���ư�\n"+
					"쵣�������Ŀ��֩�룬$N���´�ϲ����æ��֩��ץ����ڡ�\n"NOR, me);
		}
		else 
			message_vision(HIC"\n���������ã��ݴ���û���κ���״��$Nʧ�����ˡ�\n"NOR, me);
	}
	return;
}
