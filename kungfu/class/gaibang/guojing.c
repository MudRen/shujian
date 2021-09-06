#define YT_BOOK "/d/zhiye/obj/book.c"

//��������ˢ�µص㣬�������ǡ� By lsxk@hsbbs 2007/7/12
#define JOB_CHECK_PLACE "/d/xiangyang/cross2"

#include <ansi.h>
inherit NPC;
int ask_defend_job();
int ask_yt();
int ask_paiyun();

void create()
{
        set_name("����", ({"guo jing", "guo", "jing"}));
        set("nickname", HIY"����"NOR);
        set("gender", "����");
        set("age", 40);
        set("long", "�������������µĴ����������ڶ��λ�ɽ�۽���ųơ���������\n");
        set("xy_npc", "1");
        set("attitude", "friendly");
        set("str", 50);
        set("int", 10);
        set("con", 50);
        set("dex", 25);
        //set("unique", 1);
        set("no_get", 1);
        set("no_quest", 1);

        set("max_qi", 9000);
        set("max_jing", 8000);
        set("neili", 18000);
        set("max_neili", 15000);
        set("jiali", 100);
        set("eff_jingli",9000);
        set("combat_exp", 3500000);

        set_temp("special_die",1);
        set_temp("xyjob/xy_defend",1);
        set_temp("living", 1);

        set_skill("force", 300);
        set_skill("finger",300);
        set_skill("tanzhi-shentong",300);
        set_skill("yiyang-zhi",300);
        set_skill("claw",300);
        set_skill("jiuyin-baiguzhua",300);
        set_skill("huntian-qigong", 300);
        set_skill("strike", 300);
        set_skill("xianglong-zhang", 320);
        set_skill("dodge", 300);
        set_skill("jinyan-gong", 300);
        set_skill("parry", 300);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "xianglong-zhang");
        map_skill("finger","tanzhi-shentong");
        map_skill("claw", "jiuyin-baiguzhua");
        prepare_skill("strike", "xianglong-zhang");

        set("inquiry", ([
//               "�س�": (: ask_defend_job :),
                "����������": (:ask_yt:),
 //                 "����˫��": (:ask_paiyun:),

        ]) );

        set_temp("apply/damage",100);
        set_temp("apply/defence",100);
        set_temp("double_attack",1);

        set("start",1);
        set("thjob",3);
        set("gbjob",3);
        set("gmjob",3);
        set("emjob",3);
        set("job",7);
        set("finish",0);

        set("chat_chance_combat", 1000);
        set("chat_msg_combat", ({
                (: perform_action, "strike.paiyun" :),
                (: perform_action, "strike.kanglong" :),
        }));
        create_family("ؤ��", 18, "�����״�����");
        setup();

        if (clonep()) carry_object("/d/thd/obj/grn-cloth.c")->wear();
}

void init()
{
	::init();
	
	add_action("do_answer",({"answer","huida"}));
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

        command("chat ��....�ض���������...һ���ˣ�");
        command("chat �������������....��....����.....");

	if(objectp(killer = query_temp("last_damage_from")) && killer->query_temp("xyjob/mg_attack"))
		killer->add_temp("xyjob/attack", 1);
	if(objectp(killer = query_temp("last_damage_from")) && killer->query_temp("xyjob/xy_defend"))
		killer->add_temp("xyjob/defend", -1);
	::die();
}
int accept_object(object who, object obj)
{
    object me = present("guo jing", load_object("/d/xiangyang/xuanwumen"));

    if(obj->query("id")!="xiangyang mihan"){
        command("? "+ who->query("id"));
        return 0;
    }
/*
    if(JOB_CHECK_PLACE->query("xyjobing")){
        command("say �Ҿ����Ѿ��ں��ɹ��ȷ����ս�ˣ�"+who->query("name")+"�㵽���ڲ�������ܺ�������������");
        command("sigh "+ who->query("id"));
        command("kick2 "+ who->query("id"));
        call_out("destroy_letter",1,obj);
        log_file("job/xyjob", sprintf(HIR"%8s%s����xyjob������ʹ��"+HIW+"�����ܺ�"+HIR+"������������ս,����ʧ�ܡ�"NOR, ctime(time())[4..19],who->name(1)+"("+who->query("id")+")")  );
        return 1;
    }
*/ 
   command("thank "+who->query("id"));
    command("say ��л"+who->query("name")+"ǰ�����ţ�ԭ��Ŀǰ�ɹ��ȷ�����ݲ��㣬��������Ҳ����Ϊ�壡");
    command("haha");
    command("say ��㶫���͵��������ؾ��͸�"+who->query("name")+"��л��ɣ�");

         who->add("SJ_Credit",20+random(10));
         who->add("combat_exp",1000+random(1000));
         who->add("shen",1000+random(1000));
       tell_object(who, "��о�����������������������\n");
       tell_object(who, "��Ľ������������ˣ�\n");
//    me->start_call_out( (: call_other, "/d/xiangyang/cross2", "xyjob_1" :),2 );



        log_file("job/xyjob", sprintf(HIG"%8s%sʹ��"+HIW+"�����ܺ�"+HIG+"�ɹ�������������ս��"NOR, ctime(time())[4..19],who->name(1)+"("+who->query("id")+")")  );
    call_out("destroy_letter",1,obj);
    return 1;
}
void destroy_letter(object obj)
{
   if (!obj) return;
   destruct(obj);
   return;
}

int ask_defend_job()
{
	int i, a_exp = 0, d_exp= 0;
        object me, meng, room;
	object *attackers = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/mg_attack") :));
        object *defenders = filter_array("/cmds/std/xyjob"->player_list(), (: $1->query_temp("xyjob/xy_defend") :));

        me = this_player();
        room = load_object("/d/xiangyang/yingzhang");
        meng = present("meng ge", room);

  /*      if (wizardp(me))
        {
           command("say ���ɻ��ǲ�Ҫ�μӵĺ�!");
        	return 1;
        }
*/
        if (!query("ready_defend") || !meng)
        {
        	command("say Ŀǰ�ɹž���ʱ���ṥ����������Ϣһ�°ɡ�");
        	command("sweat " + me->query("id"));
        	return 1;
        }

	if (query("start_defend"))
        {
        	command("say �ɹž��Ѿ��ڽ����ˣ�����ʲô����");
        	command("sweat " + me->query("id"));
        	return 1;
        }

        if (me->query("combat_exp")<1000000)
        {
            	command("thank " + me->query("id"));
            	command("say ��л���⣬�������������˵̫Σ���ˡ�");
            	return 1;
        }

        if (me->query_conditions_by_type("poison") || me->query_conditions_by_type("hurt"))
        {
        	command("say �����о綾����ΰ������سǣ�");
        	return 1;
        }

        if (me->query_condition("killer")) {
                notify_fail("�㻹���˽��꽭����Թ������æ�ɡ�\n");
                return 1;
        }

        if (me->query_temp("xyjob"))
        {
            	command("say ���ļ����ɹž�����ʱ�������");
            	return 1;
        }

	for(i = 0; i < sizeof(defenders); i++)
	{
		d_exp += defenders[i]->query("combat_exp");
		if (query_ip_number(defenders[i]) == query_ip_number(me))
		{
			command("say ׳ʿ�����Ѿ��ڰ��������ˣ���ʲô��Ц��");
			return 1;
		}
	}
    	for(i = 0; i < sizeof(attackers); i++)
    	{
		a_exp += attackers[i]->query("combat_exp");
		if (query_ip_number(attackers[i]) == query_ip_number(me))
		{
			command("say ���Ѿ��ڰ����ɹ��ˣ��ѵ�����������ϸ��");
			return 1;
		}
	}
	if (d_exp - a_exp > 10000000)
	{
		command("say ��������Ƽ�����ס�����ǲ��ڻ��£������ͷ������ˡ�");
		command("thank " + me->query("id"));
		return 1;
	}

        command("ok");
        command("say �������ס���ţ������Ͷ���ɹŵ�����������Ϊ�ɴ��壬ֻ��ɱ֮��");
        "/cmds/std/xyjob"->add_xyjob(me);
        me->set_temp("xyjob/xy_defend", 1);
        me->set_temp("xyjob/defend", 1);
        me->set_temp("special_die", 1);
        me->set_temp("special_poison", 1);
        me->set_temp("living", 1);
        me->set_temp("apply/short", ({HIW"�������ؾ� "NOR+me->name()+"("+capitalize(me->query("id"))+")"}));
        me->apply_condition("job_busy", 100);
        me->set("job_name", "��������ս");
        return 1;
}
int ask_paiyun()
{
         object me = this_player();
	     
         if (me->query("family/family_name")!="ؤ��" ){
                 command("say ���ֲ�����ؤ����ӣ�����������");
                 return 1;
}
	if( (int)me->query_skill("xianglong-zhang", 1) < 400 )
		return notify_fail("���Ƿ����ؤ����ѧ�о���������\n");
       {
		command("whisper "+me->query("id")+" ����Ҫ����"YEL"�����һ �����⶯"NOR"��ϣ�����ܼ���Ϊؤ�������ش��ס�");
		me->set_temp("xlz/py_power", 1);
                me->add_temp("xlz/py_add",1);
		return 1;
	}
	return 1;
}
int ask_yt()
{
	object me = this_player();
	
	if(is_busy()) return 0;
	if(is_fighting()) return 0;
	
	if(me->query_skill("duanzao",1) < 220
	&& me->query_skill("caikuang",1) < 220
	&& me->query_skill("zhizao",1) < 220
	&& me->query_skill("nongsang",1) < 220 )
	{
		command("say ʲô������������Ϊ��Ϊ����֮���ߣ������������о�ʲô��������");
		return 1;
	}
	
	if(me->query("worker/guogift"))
	{
		command("say ���ϴβ������ʹ���ô������");
		command("kick3 "+me->query("id"));
		return 1;
	}
	
	me->start_busy(50);
	this_object()->start_busy(50);
	
	command("say �ض�������һλ��ǰ����������������������������˵�Ƕ������֮�ã��ض�˵���������������桶�����澭���͡��������顷����ϧ�����Բ��ߣ�һֱ������ᣬ����");
	
	message_vision(CYN"$N���´�����$n���ۡ�\n",this_object(),me);
	command("say ���������Ҳ��ꣿֻ�Ǵ��¹�ϵ�ش�ˡ����Ҫ���Ͽ�����Ĺ��������������ң�"HIY"��answer y/n��"NOR);
	me->set_temp("guo_yt",1);
	
	return 1;
}

int do_answer(string arg)
{
	object me = this_player();
	
	if(!me->query_temp("guo_yt")) return 0;
	
	if(me->query("worker/guogift")) return 0;

	if( !living(this_object()) ) return 0;
	
	if(!me->is_busy())
	{
		me->delete_temp("guo_yt");
		return 0;
	}
	
	me->delete_temp("guo_yt");
	
	if(arg && (arg=="Y" || arg=="y"))
	{
		command("ok");
		call_out("do_fight",0,me);
		return 1;
	}
	
	command("say ��Ȼ��ˣ������˰ɣ����������л��ᡭ��");
	this_object()->interrupt_me();
	this_object()->start_busy(-1);
	this_object()->interrupt_me();
	me->interrupt_me();
	me->start_busy(-1);
	me->interrupt_me();
	return 1;
}

void do_fight(object me)
{
	object ob = this_object();
	
	if(!me) return;
	
	if(me->query("worker/guogift")) return;
	
	if(environment(me)!=environment(this_object())) return;	
	
	add_temp("apply/damage",300);
	add_temp("apply/attack",300);
	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
	if(ob)
	{
		add_temp("apply/attack",-300);
		add_temp("apply/damage",-300);
		call_out("do_check",1,me);
	}
}

void do_check(object me)
{
	object ob = this_object();
	object obj;
		
	if(!me) return;
	
	if(me->query("worker/guogift")) return;
	
	if(environment(me)!=environment(this_object())) return;	
	
	if(!living(me) || me->query("qi") < 0 )
	{
		command("say ���׳־�ɼΣ��������֡���");
		message_vision(CYN"$Nҡ��ҡͷ��\n"NOR,ob);
		this_object()->interrupt_me();
		this_object()->start_busy(-1);
		this_object()->interrupt_me();
		me->interrupt_me();
		me->start_busy(-1);
		me->interrupt_me();
		return;
	}
	
	obj = new(YT_BOOK);
	obj->set_level(1+random(2));
	
	if(obj)
	{
		command("say ��ʵ��������׾��������Щ���µļ��ɣ���ֻ֪��ʦ�����ң����������գ��Դ������������ģ������Է����������ư��������ģ����Ǵ���������ļ��ܣ�����������֮��������ȥɷ�н��£���ʵ����һ��");
		command("say "+RANK_D->query_respect(me)+"��Ȼ��������֣���������һƪ��"+obj->name()+"�����ǵ�����������������ת�����㣬��Ը�����޵����������츣�ڲ�������");
		command("bow "+me->query("id"));
		message_vision("$N��$nһ"+obj->query("unit")+obj->name()+NOR"��\n",ob,me);
		
		if(obj->move(me)) me->set("worker/guogift",1);
        	me->interrupt_me();
		me->start_busy(-1);
		me->interrupt_me();		
		this_object()->interrupt_me();
		this_object()->start_busy(-1);
		this_object()->interrupt_me();		
	}
}




