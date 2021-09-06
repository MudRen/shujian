#include <ansi.h>

inherit NPC;

string ask_for(string verb);

void create()
{
        set_name("�ɸߵ���", ({ "chenggao daozhang", "chenggao" }));
        set("long", 
                "�������䵱��֧�ĵ��ӣ�������ѧ��ƫ�û��ɡ�\n"
                "��һ������һ�����������ĵİ�ɫ���ۡ�\n"
                "�������ţ��ɸߵ����书ƽƽ��ȴ���ڻ���֮����\n");

        set("no_ansuan",1);
        
        set("nickname",RED"ǧ "HIG"�� "HIM"�� "HIY"��"NOR);
                
        set("gender", "����");
        set("age", 40+random(10));
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per",10);
        set("str", 25);
        set("int", 55);
        set("con", 25);
        set("dex", 25);
                
        set("max_qi", 1500);
        set("max_jing", 800);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 2000000);
        set("score", 8000);

        set_skill("force", 280);
        set_skill("yinyun-ziqi", 280);
        set_skill("dodge", 280);
        set_skill("tiyunzong", 280);
        set_skill("xuanxu-daofa", 280);
        set_skill("blade", 280);
        set_skill("wudang-quan", 280);
        set_skill("parry", 280);
        set_skill("sword", 280);
        set_skill("taoism", 100);
        set_skill("literate", 300);
        
        set_skill("zhizao", 300);
        set_skill("nongsang", 300);
        set_skill("caikuang", 300);
        set_skill("duanzao", 300);
        
        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "wudang-quan");
        map_skill("parry", "xuanxu-daofa");
        map_skill("blade", "xuanxu-daofa");
        prepare_skill("cuff", "wudang-quan");
        
        create_family("�䵱��", 4, "����");
        set("class", "taoist");
  /*      
        set("chat_chance", 10);
	set("chat_msg", ({		
		CYN"�ɸߵ���̾Ϣһ����������������һλ������˴�������������Ҳ��֪���������޻�Ե�ٴ������д輼�ա�����\n"NOR,
		CYN"�ɸߵ���˵������Τ�����϶��Ķ���֮�����黯������ϧ��ʹ󿩣��ٺ١�����\n"NOR,
//		(: random_move :),
		CYN"�ɸߵ���˵���������������˿�������������ʰ��Ҳ���㼫Ʒ�����ꡭ����\n"NOR,

	}) );
*/	        
        set("inquiry", 
                ([
                	"nongsang" : (: ask_for, "nongsang" :),
                	"ũɣ" : (: ask_for, "nongsang" :),
                	"zhizao" : (: ask_for, "zhizao" :),
                	"֯��" : (: ask_for, "zhizao" :),
                	"duanzao" : (: ask_for, "duanzao" :),
                	"����" : (: ask_for, "duanzao" :),
                	"caikuang" : (: ask_for, "caikuang" :),
                	"�ɿ�" : (: ask_for, "caikuang" :),                        
                ]));
        setup();        
        carry_object("/d/wudang/obj/white-robe")->wear();
}

void unconcious()
{
	reincarnate();
	clear_condition(0);
	message_vision("$N��������˿�����ɫ�������ö��ˡ�\n",this_object());
}

void die()
{
	unconcious();	
}

string ask_for(string verb)
{
	object me = this_player();
	int money = 20000;
	int improve;
	if(!verb) return 0;
	
	if(is_busy()) return 0;
		
        if(me->query_skill(verb,1) < 149 || me->query_skill(verb,1) > 400  )
	{
		return 0;
	}
	
	if(me->query("potential") < 5 )
	{
		command("en "+me->query("id"));
		return 0;
	}
	
	switch (MONEY_D->player_pay(me, money)) {
		case 0:
		case 2:
		command("beg2 "+me->query("id"));
		return 0;				
	}
	
      improve = random(me->query_int() * 3 / 4) + random(me->query_skill(verb,1) / 10) + me->query_int() / 4;
	

	improve = improve*3.5;
	
	if(me->query_skill(verb,1) < 280) improve = improve*2;
		
	if (me->query("registered") ==3 && me->query_temp("ggs/started") && me->query("ggs/started") )
	{
		improve = improve*2;
		if(!random(4)) message_vision("$N�����Լ���"HIG"�������"NOR"�ϵ���Ϊ������ͨ���������Լ�ѧϰ�����°빦����\n",me);
	}
							
	me->add("potential",-5);	
	message_vision(CYN"$N�˷ܵĴ���˫��˵������ƶ��������Ȥ����̽��̽����������ء�����\n"NOR,this_object());
	tell_object(me,CYN"��ͳɸߵ���һ�����š�"HIY + to_chinese(verb) + CYN"�����ĵá�\n"NOR);
	if(WORKER_D->check_impove(me,verb,improve,3) <= 0 )
	{
		message_vision(CYN"$NͻȻ̾Ϣ������������һ����ʯ����ʯ���ɻ�Ҳ���ҿ����Ǻ��ѿ����ˡ�����\n"NOR,this_object() );
	}
me->start_busy(1+random(1));
return "����������ģ��Ǹ��������ģ����˵��Ҳ�Ǻ��е����.....%^%$^%&^^";
}
