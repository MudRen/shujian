// kuihua.c ��������
// By River@SJ 2003.1.11

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIW"��������"NOR, ({ "kuihua baodian", "baodian", "book"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��������ֵ�һ�ؼ����������䡹���ഫ��һλ����̫��������\n");
		set("value", 5000);
		set("unique", 1);
		set("no_give", 1);
		set("treasure",1);
		set("material", "paper");
		set("no_get", "�������������뿪�Ƕ���\n");
	}
	setup();
}

void init()
{
	if (environment() == this_player())
		add_action("do_du", "read");
}

int do_du(string arg)
{
	object me = this_player();
	object ob = this_object();
	mapping skills = me->query_skills();
	string *sk;
	int i;

	if (!(arg=="pixie-jian" || arg=="kuihua-shengong"))
		return notify_fail("��Ҫ��ʲô��\n");
if (arg=="pixie-jian") {
	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( !me->query("quest/pixie/pass") || me->query("gender") == "Ů��" )
		return notify_fail("������ô�õ����������䡹�İ���\n");

	if ( query("owner") != me && !wizardp(me))
		return notify_fail("������ô�õ����������䡹�İ���\n");

	if ( me->query("neili") < 1500 )
		return notify_fail("�������������\n");

	if ( me->query_skill("pixie-jian", 1) < 150 )
		return notify_fail("��ı�а�����ȼ�̫�ͣ��޷��ж����������䡹��\n");

	if (environment(me)->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (environment(me)->query("pending"))
		return notify_fail("�˵ز�����ϰ���������䡹��\n");

	if (environment(me)->query("sleep_room"))
		return notify_fail("���Ҳ�����������Ӱ�������Ϣ��\n");
 
	if (environment(me)->query("no_fight"))
		return notify_fail("�˵ز�����ϰ���������䡹��\n");

	if ( me->query("gender") == "����" ) {

		if ( me->query("marry"))
			return notify_fail("���ѽ�飬���²��ʺ���ϰ���������䡹��\n");

		if ( ! skills )
			return notify_fail("����Ҳ̫��������\n");

		sk = keys(skills);
		i = sizeof(sk);
		while (i--) {
			if (sk[i] == "dulong-dafa"
			|| sk[i] == "guiyuan-tunafa"
			|| sk[i] == "hanbing-zhenqi"
			|| sk[i] == "huagong-dafa"
			|| sk[i] == "kuihua-shengong" 
			|| sk[i] == "jiuyin-zhengong" ) continue;

			if ( SKILL_D(sk[i])->valid_enable("force"))
				return notify_fail("�㲻ɢ��"+to_chinese(sk[i])+"���޷���ϰ��а������\n");
		}
		tell_object(me, HIW"\n�����񹦣������Թ���\n\n"NOR);
		tell_object(me, HIR"���Ƿ�Ը�������Թ���ȷ����[Y|N]"NOR);
		input_to("cut_jj", me );
	}
	else {
		if ( me->query("jing") < 40 )
			return notify_fail("��ľ�̫���ˣ������ж����������䡹��\n");

		if ((!objectp(ob = present("needle", me)) ) || (!ob->query("equipped") ))
			return notify_fail("��û���廨�룬�е��޷�����������������书��\n");

		if ( me->query_skill("pixie-jian", 1) > 240 )
			return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");

		me->receive_damage("jing", 30 );
		me->add("neili", - 50);
		me->improve_skill("pixie-jian", me->query_int());
		if (!random(8))
			message("vision", me->name() + "��ϸ�ж��š��������䡹�ľ���֮����\n", environment(me), me); 
		tell_object(me, "����ϸ�ж��š��������䡹�ľ���֮����\n");
	}
	return 1;
  }
  if (arg=="kuihua-shengong") {
	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( !me->query("quest/pixie/pass") || me->query("gender") == "Ů��" )
		return notify_fail("������ô�õ����������䡹�İ���\n");

	if ( query("owner") != me && !wizardp(me))
		return notify_fail("������ô�õ����������䡹�İ���\n");

	if ( me->query("neili") < 1500 )
		return notify_fail("�������������\n");

	if ( me->query_skill("pixie-jian", 1) < 150 )
		return notify_fail("��ı�а�����ȼ�̫�ͣ��޷��ж����������䡹��\n");

	if (environment(me)->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (environment(me)->query("pending"))
		return notify_fail("�˵ز�����ϰ���������䡹��\n");

	if (environment(me)->query("sleep_room"))
		return notify_fail("���Ҳ�����������Ӱ�������Ϣ��\n");
 
	if (environment(me)->query("no_fight"))
		return notify_fail("�˵ز�����ϰ���������䡹��\n");

	if ( me->query("gender") == "����" ) {

		if ( me->query("marry"))
			return notify_fail("���ѽ�飬���²��ʺ���ϰ���������䡹��\n");

		if ( ! skills )
			return notify_fail("����Ҳ̫��������\n");

		sk = keys(skills);
		i = sizeof(sk);
		while (i--) {
			if (sk[i] == "dulong-dafa"
			|| sk[i] == "guiyuan-tunafa"
			|| sk[i] == "hanbing-zhenqi"
			|| sk[i] == "huagong-dafa"
			|| sk[i] == "kuihua-shengong" 
			|| sk[i] == "jiuyin-zhengong" ) continue;

			if ( SKILL_D(sk[i])->valid_enable("force"))
				return notify_fail("�㲻ɢ��"+to_chinese(sk[i])+"���޷���ϰ��а������\n");
		}
		tell_object(me, HIW"\n�����񹦣������Թ���\n\n"NOR);
		tell_object(me, HIR"���Ƿ�Ը�������Թ���ȷ����[Y|N]"NOR);
		input_to("cut_jj", me );
	}
	else {
		if ( me->query("jing") < 40 )
			return notify_fail("��ľ�̫���ˣ������ж����������䡹��\n");

		if ((!objectp(ob = present("needle", me)) ) || (!ob->query("equipped") ))
			return notify_fail("��û���廨�룬�е��޷�����������������书��\n");

		if ( me->query_skill("kuihua-shengong", 1) > 220 )
			return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");

		me->receive_damage("jing", 30 );
		me->set("quest/pixie/pass","pass");
		me->add("neili", - 50);
		me->improve_skill("kuihua-shengong", me->query_int());
		if (!random(8))
			message("vision", me->name() + "��ϸ�ж��š��������䡹�ľ���֮����\n", environment(me), me); 
		tell_object(me, "����ϸ�ж��š��������䡹�ľ���֮����\n");
	}
	return 1;
  }
}

private void cut_jj(string arg, object me)
{
	if( arg[0]=='y' || arg[0]=='Y' ) {
		me->set("gender", "����");
		me->set("class", "eunuch");
		CHANNEL_D->do_channel( this_object(), "rumor", sprintf("��˵%sΪ������"HIR"��а����"HIM"�������Թ��ˣ�"NOR, me->name(1)));
		log_file("quest/pixie",sprintf(HIR"%-18sΪ�ж����������䡹���������Թ���"NOR, me->name(1)+"("+capitalize(getuid(me))+")", ), me);
		tell_object(me, HIR"��ֻ�������ȼ�һ���ʹ����Ѫ�����������\n"NOR);
		me->receive_wound("qi", 4000, "�����Թ�������ʧѪ�����");
	}
	else write("�����뻹���ٿ����°ɡ�\n");
}
