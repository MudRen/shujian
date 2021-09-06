// yinggu.c ���� �������
// created by campsun 2003/12/2
//�Ƿ��ڹ������״̬���ж�Ϊquery_temp("ggs/started") ��������޸ĵ�ʱ��Ҫ�ر�ע�⡣
//LinuX@SJ 2004.2.28


#include <ansi.h>
inherit NPC;

int ask_ggs();
int ask_ggso();

void create()
{
	seteuid( getuid() );
        set_name("����", ({ "ying gu","ying"}));
        set("nickname",HIW"�������ר��"NOR);
        set("title",HIR"������"NOR);
        set("gender", "Ů��");
        set("age", 35);
        set("long", "���Ǹ��������ƺ��м�����ò��Ů�ӡ�����ȷ��һͷ�׷���ѩ����ֻ�����ﶼ����Թ�͸��ˡ�\n");
        set("attitude", "peaceful");
        set("shen_type", 0);
	set("no_get","���ö������̫���ˡ�");
        set("str", 30);
        set("int", 60);
        set("con", 30);
        set("dex", 26);
	set("per", 28);
	
	set("jiali",50);
	set_skill("force", 200);
	set_skill("huntian-qigong", 200);
	set_skill("bihai-chaosheng", 200);
	set_skill("dodge", 200);
	set_skill("xiaoyaoyou", 200);
	set_skill("parry", 200);
	set_skill("strike", 200);
	set_skill("luoying-zhang", 200);
	set_skill("hand", 200);
	set_skill("lanhua-shou", 200);
	set_skill("finger", 200);
	set_skill("tanzhi-shentong", 200);
	set_skill("sword", 200);
	set_skill("yuxiao-jian", 200);
	set_skill("literate",500);
	set_skill("qimen-bagua", 500);
	set_skill("bangjue",200);
	set_skill("dagou-bang",200);
	set_skill("stick",200);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("strike", "luoying-zhang");
	map_skill("hand", "lanhua-shou");
	map_skill("finger", "tanzhi-shentong");
	map_skill("parry", "dagou-bang");
	map_skill("sword", "yuxiao-jian");
	map_skill("stick", "dagou-bang");
	prepare_skill("hand", "lanhua-shou");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "stick.chuo" :),
		(: perform_action, "stick.ban" :),
		(: perform_action, "stick.yin" :),
		(: perform_action, "stick.chuo" :),
		(: perform_action, "stick.chan" :),
		(: perform_action, "stick.wugou" :),
		(: exert_function, "huntian" :),
	}));

	set("combat_exp", 2500000);
	set("max_qi", 5000);
	set("max_jing", 4000);
	set("neili", 7500);
	set("max_jingli", 8500);
	set("eff_jingli", 8500);
	set("max_neili", 8500);


        set("inquiry", ([
                "rumors" : "�������ô��ô���㰡����֪���ϴ�����ҽ��С����ʲôʱ�����������",
                "�ܲ�ͨ" : "��˵���������һ����ϣ��ҿ����о������������Ϊ����ȥ������",
                "���Ż�" : "���Ż���ԧ��֯����˫��....",
                "�������" : (: ask_ggs :),
                "��ʼ" 	: (: ask_ggs :),
                "start" : (: ask_ggs :),
                "����" 	: (: ask_ggso :),
                "��Ϣ" 	: (: ask_ggso :),
                "over" 	: (: ask_ggso :),
        ]));

        setup();
        carry_object(ARMOR_D("pink_cloth"))->wear();

}

int ask_ggs()
{
	object me,ob;
	int this_week = time()/86400/7;
	ob = this_object();
	me = this_player();
	
	
	if (me->query("registered")!=3)
	{
		tell_object(me, "�Բ��𰡣�Ŀǰ�������ֻ�Թ��VIP�û�����ǿ��ѧϰ���ܡ�\n");
		return 1;
	} 
	
	if(!me->query("ggs/last_week") || me->query("ggs/last_week")=="" || me->query("ggs/last_week")!=this_week)
	{
		me->set("ggs/last_week", this_week);
		me->set("ggs/started",0);
		me->set("ggs/start_time","");
		me->set("ggs/over_time","");
		me->set("ggs/left_time",10*3600);
	}

	//For all Bug By Ciwei@SJ
	while(me->query("ggs/left_time")>10*3600)
		me->add("ggs/left_time",-10*3600);

	if(me->query("ggs/left_time") < 1)
	{
		command("say ����Ȼ���ʴϻۣ�����̰������ã�������ð���ˣ�����������ѯ�ʰɡ�");
		return 1;
	}
	if(me->query("ggs/started")==1)
	{
		if(me->query_temp("ggs/started")=="")
		{
			tell_object(me, "����Ҫ������Ϣ�������ٿ�ʼʹ�ù��������\n");
		}
		else
		{
			tell_object(me, "�㲻��������ϰ�������������ô���������ץ��ʱ�䡭��\n");
			command("kick " + me->query("id"));
		}
		return 1;
	}
	
	me->set("ggs/started",1); //ʹ��״̬���
	me->set_temp("ggs/started",1); //ʹ��״̬���
	me->set("ggs/start_time",time()); //ʹ��״̬���
	
	me->apply_condition("guigushu",1); //���condition �����Զ�����
	
	command("say ���������������Щ�꾫���о�������������ܲ��򣬿��Լӱ����ѧϰ�����������");
	command("say ���������������Ԩ���������ÿ�����Ҳ��Ӧ��ʮ��Сʱ�ɡ�");
	command("look " + me->query("id"));
	command("say ������ "+ CHINESE_D->chinese_date(time(),1) + "��");
	command("say �㱾�ܻ�����ʹ�ù������"+CHINESE_D->chinese_time(me->query("ggs/left_time"))+"�����ڿ�ʼ��ʱ�ˡ�");
	log_file( "quest/ggs",sprintf("%s(%s)�ڵ�%d�ܿ�ʼ�������,ʣ:%s.\n",
			me->name(),
			me->query("id"),
			this_week,
			CHINESE_D->chinese_time(me->query("ggs/left_time"))
			));
	
return 1;
}

int ask_ggso()
{
	object me,ob;
	int user_time;
	//int an_hour = 60*60*60;
	int this_week = time()/86400/7;
	ob = this_object();
	me = this_player();
	
	if (me->query("registered")!=3)
	{
		tell_object(me, "�Բ��𰡣�Ŀǰ�������ֻ�Թ��VIP�û�����ǿ��ѧϰ���ܡ�\n");
		return 1;
	}
	if(me->query("ggs/started")!=1)
	{
		command("say ��û�п�ʼ��Ҫ��Ϣ����");
		command("pig " + me->query("id"));
		return 1;
	}
	if(me->query_temp("ggs/started")!=1)
	{
		command("say ���ǲ���û����Ϣ�������ˣ�����ʱ��Ͱ������ϴ�����ʱ����ɡ�");
		me->set("ggs/over_time",FINGER_D->get_last_on(me->query("id")));		
	}
	else
	{	
		me->set("ggs/over_time",time());	
	}
	
	user_time=(int)me->query("ggs/over_time")-(int)me->query("ggs/start_time");
	command("say �ǰ������ݽ�ϣ�����������ˣ��Ǹ���Ϣ��Ϣ��");
	command("look " + me->query("id"));
	
	command("say ��Ĺ��������ʼʱ���ǣ�" + CHINESE_D->chinese_date((int)me->query("ggs/start_time"),1) + "��");
	command("say             ����ʱ���ǣ�" + CHINESE_D->chinese_date((int)me->query("ggs/over_time"),1) + "��");
	command("say �����һ�������ˣ�" + CHINESE_D->chinese_time(user_time)+"��");
	me->set("ggs/left_time",me->query("ggs/left_time") - user_time);

	log_file( "quest/ggs",sprintf("%s(%s)�ڵ�%d�ܽ���ggs,ʣ:%s,��:%s.\n",
			me->name(),
			me->query("id"),
			this_week,
			CHINESE_D->chinese_time(me->query("ggs/left_time")),
			CHINESE_D->chinese_time(user_time)
			));



	if (me->query("ggs/left_time") < 0 ) //��ֹbug
		me->set("ggs/left_time",0);
		
	if (me->query("ggs/left_time")) 	
		command("say �㱾�ܻ�����ʹ�ù������"+CHINESE_D->chinese_time(me->query("ggs/left_time"))+"��");
	else
		command("say ��Ĺ������ʱ�������ˣ����������ɡ�");
	
	me->set_temp("ggs/started",0);
	me->set("ggs/started",0);
	me->set("ggs/start_time","");
	me->set("ggs/over_time","");	
	
	me->clear_condition("guigushu"); //�����


return 1;	
}

//����
int accept_fight(object ob){
        command("say ��λ"+RANK_D->query_respect(ob)+"���书����������ģ����Ǻö��Σ�");
}
int hit_ob(object ob)
{
        command("say ��λ"+RANK_D->query_respect(ob)+"���书����������ģ����Ǻö��Σ�");
}


void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        command("swear");
}

void unconcious()
{
	message_vision(YEL"$NͻȻ���ù��֮����ȫ��������ɫ�ʣ�����ս����֮�ơ�\n"NOR, this_object());
        reincarnate();
        add("str",10); //Խ��Խ�£�^_^
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        clear_conditions_by_type("poison");
}

void die()
{
        unconcious();
}