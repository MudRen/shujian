//��������ˢ�µص㣬�������ǡ� By lsxk@hsbbs 2007/7/10
#define JOB_CHECK_PLACE "/d/xiangyang/cross2"

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
int ask_attack();

void create()
{
    	set_name("�ɸ�", ({ "meng ge", "meng", "ge" }));
    	set("title","�ɹ�Ԫ˧");
    	set("gender", "����");
    	set("long", "���Ǵ˴θ�������������ɹ�Ԫ˧��\n");
    	set("age", 25);
    	set("str", 30);
    	set("int",20);
    	set("con",30);
    	set("dex",20);
    	set("combat_exp", 300000);
    	set("attitude", "friendly");
    	set("max_qi",2000);
    	set("max_jing",1000);
    	set("neili",2000);
    	set("max_neili",2000);
    	set("qi",2000);
    	set("jing",1000);
    	set("jingli",1000);
    	set("score", 100);
    	set("unique", 1);
        set("no_get", 1);
    	set("no_quest",1);

    	set_temp("special_die",1);
    	set_temp("xyjob/mg_attack",1);
    	set_temp("living", 1);

    	set_skill("force", 100);
    	set_skill("dodge", 100);
    	set_skill("parry", 100);
        set_skill("yijin-jing", 100);
        set_skill("shaolin-shenfa", 100);
        set_skill("blade", 100);
        set_skill("xiuluo-dao",100);
        set_skill("buddhism", 100);
        set_skill("literate", 100);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "xiuluo-dao");
        map_skill("blade", "xiuluo-dao");

// ��������
        set("sljob",3);
        set("xxjob",4);
        set("xsjob",2);
        set("gjob",1);
        set("job",6);

        set("inquiry", ([
//                "����": (: ask_attack :),
        ]) );

        setup();
        carry_object("/clone/weapon/blade")->wield();
        carry_object("/clone/armor/armor")->wear();
}
int accept_object(object who, object obj)
{
    object me = present("meng ge", load_object("/d/xiangyang/yingzhang"));

    if(obj->query("id")!="menggu mihan"){
        command("? "+ who->query("id"));
        return 0;
    }
/*
    if(JOB_CHECK_PLACE->query("xyjobing")){
        command("say �Ҿ����Ѿ��ں������ؾ���ս�ˣ�"+who->query("name")+"�㵽���ڲ�������ܺ�������������");
        command("sigh "+ who->query("id"));
        command("kick2 "+ who->query("id"));
        call_out("destroy_letter",1,obj);
        log_file("job/xyjob", sprintf(HIR"%8s%s����xyjob������ʹ���ɹ��ܺ�������������ս,����ʧ�ܡ�"NOR, ctime(time())[4..19],who->name(1)+"("+who->query("id")+")")  );
        return 1;
    }
  */
  command("thank "+who->query("id"));
    command("say ��л"+who->query("name")+"ǰ�����ţ�ԭ��Ŀǰ�����ؾ����㣬�������ɹŽ����ĺ�ʱ����");
    command("grin");
    command("say ��㶫���͵������͸�"+who->query("name")+"��л��ɣ�");
         who->add("shen",-(1000+random(2000)));
         who->add("combat_exp",1000+random(1000));
         who->add("SJ_Credit",20+random(10));
       tell_object(who, "���æ���ż�Ц�˼�����\n");
       tell_object(who, "��Ľ������������ˣ�\n");    


//    me->start_call_out( (: call_other, "/d/xiangyang/cross2", "xyjob_1" :),2 );
  
     log_file("job/xyjob", sprintf(HIG"%8s%sʹ��"+HIR+"�ɹ��ܺ�"+HIG+"�ɹ�������������ս��"NOR, ctime(time())[4..19],who->name(1)+"("+who->query("id")+")")  );
    call_out("destroy_letter",1,obj);
    return 1;
}
void destroy_letter(object obj)
{
   if (!obj) return;
   destruct(obj);
   return;
}

int ask_attack()
{
        int i, a_exp = 0, d_exp= 0;
        object me, guo, room;
       	object *attackers, *defenders;

	me = this_player();
        room = load_object("/d/xiangyang/xuanwumen");
        guo = present("guo jing", room);

/*   if(wizardp(me))
	{
           command("say ���ɻ��ǲ�Ҫ�μӵĺ�!");
		return 1;
	}
*/
        if (!query("ready_attack") || !guo)
        {
            	command(" say Ŀǰ�Ҿ��ȷ��޷������������أ������������о���Ӧ֮�ߡ�");
            	return 1;
        }

	if (query("start_attack"))
        {
            	command(" say �Ҿ��Ѿ���ʼ�����ˣ������ˣ�");
            	return 1;
        }

        if (me->query("combat_exp")<1000000)
        {
            	command("sneer");
            	command("say ��ƾ����������è�Ĺ����ܸ�ʲô?");
            	return 1;
        }

	if (me->query_conditions_by_type("poison") || me->query_conditions_by_type("hurt"))
        {
        	command("say �����о綾����ΰ����ҹ��ǣ�\n");
        	return 1;
        }

        if (me->query_condition("killer")) {
                notify_fail("�㻹���˽��꽭����Թ������æ�ɡ�\n");
                return 1;
        }

        if (me->query_temp("xyjob"))
        {
            	command("say ���ļ����������ˣ��Ҿͻ����ս��");
           	return 1;
        }
        if (!"/cmds/std/xyjob"->player_list())
        	"/cmds/std/xyjob"->add_xyjob(me);

        defenders = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/xy_defend") :));
 	attackers = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/mg_attack") :));
        for(i = 0; i < sizeof(defenders); i++)
        {
		d_exp += defenders[i]->query("combat_exp");
		if (query_ip_number(defenders[i]) == query_ip_number(me))
		{
			command("say ���Ѿ��ڷ��������ˣ��ѵ�����������ϸ��\n");
			return 1;
		}
	}
    	for(i = 0; i < sizeof(attackers); i++)
	{
		a_exp += attackers[i]->query("combat_exp");
		if (query_ip_number(attackers[i]) == query_ip_number(me))
		{
			command("say ׳ʿ�����Ѿ��ڰ��������ˣ���ʲô��Ц��\n");
			return 1;
		}
	}
    	if (a_exp - d_exp > 10000000)
	{
		command("say �Ҿ������ڶ࣬�������������練�ƣ������ͷ������ˡ�\n");
		return 1;
	}

        command("ok");
        command("say ����ڴ�׼�����ȴ��ҵľ�������Ҿ������������ȷ�!");
        "/cmds/std/xyjob"->add_xyjob(me);
        me->set_temp("special_die", 1);
        me->set_temp("special_poison", 1);
        me->set_temp("xyjob/attack", 1);
        me->set_temp("xyjob/mg_attack", 1);
        me->set_temp("living", 1);
        me->set_temp("apply/short", ({HIR"�ɹ��ȷ�� "NOR+me->name()+"("+capitalize(me->query("id"))+")"}));
        me->apply_condition("job_busy", 100);
        me->set("job_name", "��������ս");
        return 1;
}

void kill_ob(object me)
{
	if (!me->query_temp("xyjob") || !me->query_temp("living"))
	{
        	me->remove_killer(this_object());
 		remove_killer(me);
 		return;
 	}
        ::kill_ob(me);
}

void die()
{
        object killer;

        command("chat �ɶ񰡣�������... ������ǰ��...");
        command("chat* dead");

        if(objectp(killer = query_temp("last_damage_from")) && killer->query_temp("xyjob/xy_defend"))
                killer->add_temp("xyjob/defend", 1);
        if(objectp(killer = query_temp("last_damage_from")) && killer->query_temp("xyjob/mg_attack"))
                killer->add_temp("xyjob/attack", -1);
        ::die();
}
