// fengling.c ����ʦ̫
// Lklv modify at 2001.10.18
// Add quest by Lane@SJ 2005.5.13 ��ɫ������

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

mixed em_jianjue();

void create()
{
	set_name("����ʦ̫", ({ "fengling shitai", "fengling", "shitai"}));
	set("long","�����Ƕ����ɵڶ��������˷���ʦ̫�ˡ�\n"
		"����Ŀ���飬����Ѱ������һ�㣬�벻��һ˿����֮����\n"
	);

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("unique", 1);
	set("class", "bonze");
	set("age", 80);
	set("shen", 20000);
	set("str", 26);
	set("int", 30);
	set("con", 29);
	set("dex", 30);
	set("per", 30);

	set("max_qi", 6700);
	set("max_jing", 6000);
	set("eff_jingli", 3500);
	set("neili", 15000);
	set("max_neili", 14000);
	set("jiali", 150);
	set("emei/jianjue", 1);
	set("combat_exp", 2800000);

	set_skill("dacheng-fofa", 200);
	set_skill("linji-zhuang", 220);	// ���� 20 level
	set_skill("jieshou-jiushi", 280);
	set_skill("huifeng-jian", 280);
	set_skill("sixiang-zhang", 280);
	set_skill("yanxing-daofa", 280);
	set_skill("hand", 280);
	set_skill("literate", 150);
	set_skill("strike", 280);
	set_skill("linji-jianzhen", 200);
	set_skill("sword", 280);
	set_skill("blade", 280);
	set_skill("parry", 280);
	set_skill("dodge", 280);
	set_skill("force", 220);	// ���� 20 level
	set_skill("anying-fuxiang", 280);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("blade", "yanxing-daofa");
	map_skill("parry", "jieshou-jiushi");
	map_skill("dodge", "anying-fuxiang");
	map_skill("strike", "sixiang-zhang");
	map_skill("hand", "jieshou-jiushi");
	prepare_skill("hand", "jieshou-jiushi");

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
		(: perform_action, "sword.liaoyuan" :),
		(: perform_action, "hand.foguang" :)
	}));
	create_family("������", 2, "ǰ����");

	set("inquiry", ([
		"���ҽ���" : (: em_jianjue :),
		"����" : (: em_jianjue :),
	]));

	setup();
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 40);
	set_temp("apply/attack", 50);
	set_temp("apply/dodge", 40);
	if(random(2)==1)
		carry_object(BINGQI_D("gangjian"))->wield();
	UPDATE_D->get_cloth(this_object());
}

void init()
{
	object me, ob;
	::init();
	ob = this_player();
	me = this_object();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_qingjiao", "qingjiao");

}

void greeting(object me)
{
	int shen;
	if(!me) return;
	shen = me->query("shen");
	if(shen <= -200000 && me->query("family/family_name") == "������"){
		command("chat* smash "+me->query("id"));
		command("say ���������������а�����ٺ�аħ��������ҿ�����������ɣ�");
	}
	if(shen <0 && shen > -200000 && me->query("family/family_name") == "������"){
		command("look "+me->query("id"));
		command("say �ҿ����������������а��������ǲ�������������ʲô���£�");
	}
	else command("say �����ӷ�");
}

int accept_object(object me, object ob)
{
	if( me->query("family/family_name") != "������" ) return 0;

	if( ob->query("id") != "zhi huan" || !me->query_temp("marks/pass_yitian") ) return 0;

	if( !(me->query_temp("marks/get_ring")) ) {
		command("say ��öָ���ǴӺζ������ߣ���ƭ���ᣬû��ô���ף�");
		command("consider " + me->query("id"));
		command("say �������ɣ�");
		kill_ob(me);
		return 1;
	} else {
		command("say �ðɣ���Ȼ������ָ���������ң�������ʸ���������²������ˡ�\n");
		me->delete_temp("marks/pass_yitian");
		me->delete_temp("marks/get_ring");
		me->set_temp("bai_feng",1);
		remove_call_out("destroying");
		call_out("destroying", 1, me, ob);
		return 1;
	}
	return 0;
}

void attempt_apprentice(object ob)
{
	object me;
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");
	ob_fam = ob->query("family");
	name = ob->query("name");

        if (ob->query("family/family_name") != "������" || !ob->query("family")){
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
        }
        if ((string)ob->query("class")!="bonze" && ob->query("family/family_name") == "������"){
                command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ����ܰ�����������ѧ�ա�");
                return;
        }
	if ((int)ob->query_skill("linji-zhuang", 1) < 150 ){
		command("say �����Ҳ�����������֮�ˣ��㻹�Ƕ���������ټ�ʮ��ׯ�ɡ�");
		return;
	}
        if (!ob->query_temp("bai_feng")){
		command("say " + RANK_D->query_respect(ob) + "����û���õ�����ָ�������ܰ�����Ϊʦ��");
		return;
	}
	if (ob_fam["generation"] == (my_fam["generation"] + 1)){
		command("say ͽ�����㹦�����������?\n");
		ob->delete_temp("bai_feng");
		return;
	}
	if ( ob_fam["generation"] == (my_fam["generation"] + 2) ){
		if ( ob->query_temp("bai_feng") ){
			ob->delete_temp("bai_feng");
			command("chat ���ᴹ��֮�꣬�յõ�һ���²����ˣ����ǿ�ϲ�ɺ� !");
			name = ob->query("name");
			new_name = "��" + name[2..3];
			ob->set("name", new_name);
			command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ���Ϊ���ֱ�����֮һ !");
			command("recruit " + ob->query("id"));
                        ob->set("title", HIW"��������������"NOR);
			return;
		}
		command("say ��û������ָ�����Ҳ��ܰ��²����㡣\n");
		return;
	}
	command("say ��౲���ϣ�����Խ����ʦ��\n");
	return;
}

void destroying(object me, object obj)
{
	if (!obj) return;
	destruct(obj);
	return;
}

mixed em_jianjue()
{
	object me = this_player();
	object ob = this_object();
	int exp, time;

	if( me->query("family/family_name") != "������" )
		return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";

	if( me->query_temp("marks/ʧ��") ) {
		message_vision(CYN"$N��Ŀ���飬����$n����˵����������֮�����ڲ������£��㰲������������һ����������ѧ����߾��磡��\n"NOR,ob, me);
		return 1;
	}

        if( me->query("emei/jianjue") ) { me->set("title",HIW"�����ɻط罣������"NOR);
                return RANK_D->query_respect(me) + "����Ľ��������Ѿ�����ƶ��֮���ˣ��ֺιʿ�����Ц�أ�";}

	if( me->query_skill("huifeng-jian", 1) < 200 )
		return RANK_D->query_respect(me) + "����Ľ������費�������޷��������ɽ����ľ�Ҫ���ڣ�";

/*	if( me->query_skill("huifeng-jian", 1) > 400 )
		return RANK_D->query_respect(me) + "�Ķ��ҽ�����տ�ޱȣ�Ӧ�ò�����������ɣ�";
*/
	time = time() - me->query("em_jianjue/time");
	if( me->query("em_jianjue/time") && time < 86400 && !wizardp(me) )
		return "�ţ��㲻�Ǹ�����̹��ҽ����𣿻�����Ŭ����ʱ��ɣ�";

	exp = me->query("combat_exp") - me->query("em_jianjue/exp");
        if( me->query("em_jianjue/exp") && exp < 100000 && !me->query("cw_exp") )
		return "�ţ��㲻�Ǹ�����̹��ҽ����𣿻�����Ŭ����ʱ��ɣ�";

	if( me->query_temp("marks/qingjiao") )
		return RANK_D->query_respect(me) + "���ҸղŲ����Ѿ��ش�������";

	message_vision(CYN"$N����Ŀ���$n������˵���������ɵĻط���������������Ƿ��Բ֮ͨ������սʱǧ����q�������޾���\n"
	"�粻�����������ƺ������򣬽�������书������С�ɣ�����������ģ����Դ������콣���������һ�¡�("HIY"qingjiao"CYN")��\n"NOR, ob, me);

	me->set_temp("marks/qingjiao", 1);
	return 1;
}

int do_qingjiao()
{
	object me, ob, weapon, weapon1;

	me = this_player();
	ob = this_object();

	weapon1 = ob->query_temp("weapon");

	if( !me->query_temp("marks/qingjiao") ) return notify_fail("ʲô��\n");

	if( me->is_busy() || me->is_fighting() ) return notify_fail("����æ���ء�\n");

	if( ob->is_busy() || ob->is_fighting() ) return notify_fail(ob->name()+"��æ���ء�\n");

	if( me->query("qi") < me->query("max_qi")*3/10 )
		return notify_fail("������״̬���ѣ����ǵȻ�����̰ɣ�\n");

	if( me->query("eff_qi") < me->query("max_qi")/2 )
		return notify_fail("�����������������ǵȻ�����̰ɣ�\n");

	if( !weapon = present("yitian jian", me) ) {
		message_vision(CYN"$N��$n˵��������ʦָ̫��"+RANK_D->query_self(me)+"�Ķ��ҽ����ɣ���\n"NOR, me, ob);
		message_vision(CYN"$n˵����" + RANK_D->query_respect(me) + "������ȥ�����콣�����ɣ���\n"NOR, me, ob);
		me->start_busy(1);
		return 1;
	} else {
		me->start_busy(1);
		message_vision(CYN"$N����$n���������ĵ������콣˵����������ʦָ̫��"+RANK_D->query_self(me)+"�Ķ��ҽ����ɣ���\n"NOR, me, ob);
		me->delete_temp("marks/qingjiao");
		me->set("em_jianjue/time", time());
		me->set("em_jianjue/exp", me->query("combat_exp"));

		if( weapon1 ) weapon1->unequip(ob); 
		weapon->move(ob);
		weapon->wield(ob);
		ob->set("jiali", 150);
		ob->set("neili", query("max_neili")*2 );
		ob->set("jingli", query("eff_jingli")*2 );
		message_vision(HIW"$nĬ����ҽ�������"HBRED+HIW"ǰ�����ң�ȫ�޶��򣬺����ˣ��ȷ������ˡ�"NOR+HIW"����ʱ�����ݺᣬ��$N�������ֲ�����"NOR, me, ob);
		ob->set_temp("jianjue", 1);
		COMBAT_D->do_attack(ob, me, weapon, 1);
		if( me->query("qi") >= me->query("max_qi")*3/10 ) COMBAT_D->do_attack(ob, me, weapon, 1);
		if( me->query("qi") >= me->query("max_qi")*3/10 ) COMBAT_D->do_attack(ob, me, weapon, 1);
		if( me->query("qi") >= me->query("max_qi")*3/10 ) {
			message_vision(HIW"$nĬ����ҽ�������"CYN"������ʹ�����˲��Ӽ����ɼ����ͣ�������"HIW"�������͵��˽���ת�����ֽ��־�ʽ�澢����"NOR, me, ob);
			weapon->unequip(ob); 
			COMBAT_D->do_attack(ob, me, 0, 1);
			weapon->wield(ob);
		}
		if( me->query("qi") >= me->query("max_qi")*3/10 ) COMBAT_D->do_attack(ob, me, weapon, 1);
		if( me->query("qi") >= me->query("max_qi")*3/10 ) {
			message_vision(HIW"$nĬ����ҽ�������"HIY"�����ܴ��ģ��ɼ��Դ��ˡ�ǰ�����ˣ�����ǡ�ϡ�"HIW"��������"+weapon->name()+HIW"�͵Ļ�ת�ٴδ̳���"NOR, me, ob);
			COMBAT_D->do_attack(ob, me, weapon, 1);
		}
		ob->delete_temp("jianjue");

		if( me->query("qi") < me->query("max_qi")*3/10 ) {
			message_vision(CYN"$n�ǳ�ʧ���Ķ�$N˵������"+me->name()+"�����书δ�ɣ����ǵ����û�����˵�����콣��ʱ�����Ұ��㱣�ܰɣ���\n"NOR, me, ob);
			weapon->unequip(ob); 
			destruct(weapon);
			if( weapon1 ) weapon1->wield(ob);
			me->start_busy(1);
			me->set_temp("marks/ʧ��", 1);
			return 1;
		}
		weapon->unequip(ob); 
		weapon->move(me);
		message_vision(CYN"\n$n�����콣������$N������˵�ţ���"+me->name()+"�����Լ�������ĥ������ʹ�õĽ����ɣ���\n"NOR, me, ob);
		if( weapon1 ) weapon1->wield(ob);
		message_vision(HIY"\n$Nƴ���ػ����Ÿղŵ���������ʼ����˼����.........\n", me);
                if( random(10) && ( random(me->query_int()) > 35 || random(me->query_con()) > 35 ) ) {   // ��� + ���ǻ������� ��
			message_vision(HIW"$NͻȻ��׽ס����˲���һĻ�����������ǰ�����ң�ȫ�޶��򣬺����ˣ��ȷ������ˡ���������������ҽ��������С�\n", me);
			tell_object(me, BYEL"��ϲ�㣬����" + NATURE_D->game_time() + "�����˶��ҽ�����\n"NOR);
			me->set("emei/jianjue", 1);
		} else {
			message_vision(HIC"$Nҡ��ҡͷ�������������Ǻ����ѵġ���˵�գ������̾�˿�����\n", me);
			me->set_temp("marks/ʧ��", 1);
		}
	}
	return 1;
}

