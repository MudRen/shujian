// qiu.c �𴦻�
// Modified By action@SJ 2008/8/12
// Update By action@SJ 2009/2/21
//ţ�Ҵ��𴦻�2010/07/27

#include <ansi.h>

inherit NPC;
//inherit F_MASTER;

//mixed qzjf_jianjue();

void create()
{
	set_name("�𴦻�", ({"qiu chuji", "qiu"}));
	set("long",
                "�����ǽ������˳ơ������ӡ����𴦻������ˣ�����������\n"
                "�����⣬��ĿԲ����˫ü�絶����ò���ϣ�ƽ���������\n");
	set("title","ȫ������֮��");
	set("gender", "����");
	set("age", 32);
	set("nickname",HIM"������"NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 50);
	set("int", 55);
	set("con", 50);
	set("dex", 50);

	      set("max_qi", 4800000);
        set("jing", 240000);
        set("max_jing", 240000);
        set("neili", 510000);
        set("max_neili", 510000);
        set("jiali", 200);
        set("combat_exp", 4000000);
        set_skill("force", 350);
        set_skill("xiantian-gong", 350);
        set_skill("sword", 350);
        set_skill("quanzhen-jianfa",350);
        set_skill("dodge", 350);
        set_skill("jinyan-gong", 350);
        set_skill("parry", 350);
        set_skill("strike", 350);
        set_skill("haotian-zhang", 350);
        set_skill("literate", 200);
        set_skill("hand",350);
        set_skill("finger", 350);
        set_skill("taoism",200);
	      set_skill("medicine", 200);
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike","haotian-zhang");
        set_skill("tiangang-beidouzhen", 140);
        
	      create_family("ȫ���", 2, "����");
	      set("inquiry", ([               
               // "����" : (: qzjf_jianjue :),
                           
        ]));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sanqing" :),
               // (: perform_action, "sword.qixing" :),
                //(: perform_action, "strike.lianhuan" :),
               
        }));
        	setup();
	carry_object("/d/wudang/obj/greenrobe")->wear();
	carry_object("/clone/weapon/sword")->wield();
	add_money("silver",50);
}

void init()
{
	object me, ob;
	::init();
	ob = this_player();
	me = this_object();

	add_action("do_qingjiao", "qingjiao");

}

void attempt_apprentice(object ob)
{
       if ((int)ob->query("shen") < 100000) {
               command("say ��ȫ������������������ɣ��Ե���Ҫ���ϡ�");
               command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                       "�Ƿ����ò�����");
               return;
       }
       command("say �ðɣ�ƶ�����������ˡ�");
       command("recruit " + ob->query("id"));
       ob->set("class","taoism");
}

mixed qzjf_jianjue()
{
	object me = this_player();
	object ob = this_object();
	int exp, time, night;
	mixed *local;
	night = 0;
	local = localtime(time() * 60);
	if (local[2] < 5 || local[2] >= 19) night = 1;

	if( me->query("family/family_name") != "ȫ���" )
		return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";

  if (!night) 
	  return "�������޷���������б������ǣ������ָ����ѧϰȫ�潣���Ľ������衣\n";

	if( me->query("quest/qzjf/jianjue") )
		return RANK_D->query_respect(me) + "����Ľ��������Ѿ����ڱ���֮���ˣ��ֺιʿ�����Ц�أ�";

	if( me->query_skill("quanzhen-jianfa", 1) < 300 )
		return RANK_D->query_respect(me) + "����Ľ������費�������޷��������ɽ����ľ�Ҫ���ڣ�";

	time = time() - me->query("qzjf/jianjue/time");
	if( me->query("qzjf/jianjue/time") && time < 86400 && !wizardp(me) )
		return "�ţ��㲻�Ǹ�����̹��ҽ����𣿻�����Ŭ����ʱ��ɣ�";

	exp = me->query("combat_exp") - me->query("qzjf/jianjue/exp");
	if( me->query("qzjf/jianjue/exp") && exp < 100000 && !wizardp(me) )
		return "�ţ��㲻�Ǹ�����̹��ҽ����𣿻�����Ŭ����ʱ��ɣ�";

	if( me->query_temp("marks/qzjf/qingjiao") )
		return RANK_D->query_respect(me) + "���ҸղŲ����Ѿ��ش�������";

	message_vision(CYN"$N����Ŀ���$n������˵���������ɵ�ȫ�潣���������ǵ��ҹ۲������Ƕ��������Ǳ任֮����ȡǧ���򻯡������޾�֮ԭ��\n"
	"�粻�����������ƺ������򣬽�������书������С�ɣ�����������ģ��������������һ�¡�("HIY"qingjiao"CYN")��\n"NOR, ob, me);

	me->set_temp("marks/qzjf/qingjiao", 1);
	return 1;
}

int do_qingjiao()
{
	object me, ob, weapon, weapon1;

	me = this_player();
	ob = this_object();

	weapon1 = ob->query_temp("weapon");

	if( !me->query_temp("marks/qzjf/qingjiao") ) return notify_fail("ʲô��\n");

	if( me->is_busy() || me->is_fighting() ) return notify_fail("����æ���ء�\n");

	if( ob->is_busy() || ob->is_fighting() ) return notify_fail(ob->name()+"��æ���ء�\n");

	if( me->query("qi") < me->query("max_qi")*9/10 )
		return notify_fail("������״̬���ѣ����ǵȻ�����̰ɣ�\n");

	if( me->query("eff_qi") < me->query("max_qi")/2 )
		return notify_fail("�����������������ǵȻ�����̰ɣ�\n");

	if( !weapon = present("qixing jian", me) ) {
		message_vision(CYN"$N��$n˵������ʦ����ͽ������ָ��"+RANK_D->query_self(me)+"��ȫ�潣����������\n"NOR, me, ob);
		message_vision(CYN"$n˵����" + RANK_D->query_respect(me) + "������ȥ����ʦ��������ȡ�����ǽ��ɣ���\n"NOR, me, ob);
		me->start_busy(1);
		return 1;
	} else {
		me->start_busy(1);
		message_vision(CYN"$N����$n����������ʦ��˵��������ʦ��ָ��"+RANK_D->query_self(me)+"��ȫ�潣����������\n"NOR, me, ob);
		me->delete_temp("marks/qzjf/qingjiao");
		me->set("qzjf/jianjue/time", time());
		me->set("qzjf/jianjue/exp", me->query("combat_exp"));

		if( weapon1 ) weapon1->unequip(ob); 
		weapon->move(ob);
		weapon->wield(ob);
		ob->set("jiali", 0);
		ob->set("neili", query("max_neili")*2 );
		ob->set("jingli", query("eff_jingli")*2 );
		message_vision(HIW"$nĬ��ȫ�潣������"HBRED+HIW"�����ȴӱ��������ɱ�������չ������"NOR+HIW"����ʱ�����ݺᣬ��$N�������ֲ�����"NOR, me, ob);
		ob->set_temp("qzjf/jianjue", 1);
		COMBAT_D->do_attack(ob, me, weapon, 1);
		if( me->query("qi") >= me->query("max_qi")*1/10 ) COMBAT_D->do_attack(ob, me, weapon, 1);
		if( me->query("qi") >= me->query("max_qi")*1/10 ) COMBAT_D->do_attack(ob, me, weapon, 1);
		if( me->query("qi") >= me->query("max_qi")*1/10 ) {
			message_vision(HIW"$nĬ��ȫ�潣������"HBMAG+HIW"������ָ�����½Դ���������ָ�����½��ġ�"NOR+HIW"�������͵��˽���ת����������ָ��֮��һ��ָ���澢����"NOR, me, ob); 
			weapon->unequip(ob); 
			COMBAT_D->do_attack(ob, me, 0, 1);
			weapon->wield(ob);
		}
		if( me->query("qi") >= me->query("max_qi")*1/10 ) COMBAT_D->do_attack(ob, me, weapon, 1);
		if( me->query("qi") >= me->query("max_qi")*1/10 ) {
			message_vision(HIW"$nĬ��ȫ�潣������"HBBLU+HIW"������ָ�����½��������ָ�����½Զ���"NOR+HIW"��������"+weapon->name()+HIW"�͵Ļ�ת�ٴδ̳���"NOR, me, ob);
			COMBAT_D->do_attack(ob, me, weapon, 1);
		}
		ob->delete_temp("qzjf/jianjue");

		if( me->query("qi") < me->query("max_qi")*1/20 ) {
			message_vision(CYN"$n�ǳ�ʧ���Ķ�$N˵������"+me->name()+"�����书δ�ɣ����ǵ����û�����˵����\n"NOR, me, ob);
			weapon->unequip(ob); 
			destruct(weapon);
			if( weapon1 ) weapon1->wield(ob);
			me->start_busy(1);
			me->set_temp("marks/ʧ��", 1);
			return 1;
		}
		weapon->unequip(ob); 
		weapon->move(me);
		message_vision(CYN"\n$n�����ǽ�������$N������˵�ţ���"+me->name()+"�����Լ�������ĥ������ʹ�õĽ����ɣ���\n"NOR, me, ob);
		if( weapon1 ) weapon1->wield(ob);
		message_vision(HIY"\n$Nƴ���ػ����Ÿղŵ���������ʼ����˼����.........\n", me);
		if( random(me->query("kar")) > 25) {	// �����Դ
			message_vision(HIW"$NͻȻ��׽ס����˲���һĻ�����������ǰ�����ң�ȫ�޶��򣬺����ˣ��ȷ������ˡ������������ȫ�潣�������С�\n", me);
			tell_object(me, BYEL"��ϲ�㣬����" + NATURE_D->game_time() + "������ȫ�潣����\n"NOR);
			me->set("quest/qzjf/jianjue", 1);
		} else {
			message_vision(HIC"$Nҡ��ҡͷ�������������Ǻ����ѵġ���˵�գ������̾�˿�����\n", me);
			me->set_temp("marks/ʧ��", 1);
		}
	}
	return 1;
}

