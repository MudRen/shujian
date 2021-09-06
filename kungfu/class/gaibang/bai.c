// bai.c ������
// By Looklove@SJ 2000/9/27
// Looklove modified 2001.5.25 �Ƕ���
// tangfeng modified 2004.8 For tlbb
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "begger.h";
string ask_dao();
int ask_xiaofeng();

#define QUESTDIR "quest/�����˲�/"
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"

void create()
{
        set_name("������", ({ "bai shijing", "bai"}));
        set("title", HIW"ؤ��ִ������"NOR);
        set("gb/bags",9);
        set("gender", "����");
        set("age", 47);
        set("long", "������ؤ���е�ִ�����ϣ�����������˽��\n"
        	    "���д�С�˵ȣ���Ȼ����Υ�����������������Ҳ�Ǿ������֡�\n");
        set("attitude", "peaceful");
        set("unique", 1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("qi", 2400);
        set("max_qi", 2400);
        set("jing", 1600);
        set("max_jing", 1600);
	set("eff_jingli", 1600);
        set("neili", 3400);
        set("max_neili", 3400);
        set("jiali", 100);
        set("combat_exp", 1500000);

        set_skill("force", 150);
        set_skill("huntian-qigong", 150);
        set_skill("dodge", 150);
        set_skill("xiaoyaoyou", 150);
        set_skill("parry", 130);
        set_skill("strike", 150);
        set_skill("lianhua-zhang",150);
        set_skill("hand", 120);
        set_skill("suohou-shou", 100);
        set_skill("begging", 90);

        map_skill("force", "huntian-qigong");
        map_skill("parry","lianhua-zhang");
        map_skill("strike","lianhua-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("hand", "suohou-shou");
        prepare_skill("strike", "lianhua-zhang");
    	set("chat_chance_combat", 90);
    	set("chat_msg_combat", ({
        	(: perform_action, "strike.cailian" :),
        	(: perform_action, "strike.bingdi" :),
        	(: exert_function, "huntian" :),
        }));

        create_family("ؤ��", 18, "�Ŵ�����");

        set("inquiry", ([
                "ؤ��" : "����ؤ�������µ�һ��\n",
                "�Ƿ�" : "�����������壬���ǵ�ǰ�ΰ�����\n",
		            "����" : (: ask_xiaofeng :),
		            "���־���" : (: ask_xiaofeng :),
		            "ؤ������" : (: ask_xiaofeng :),
		            "���־��" : (: ask_xiaofeng :),
	        "����" : (: ask_dao :),
        ]));
        setup();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        carry_object(__DIR__"obj/gb_budai9")->wear();
}

void attempt_apprentice(object ob)
{
        if (ob->query("family/family_name")
        && ob->query("family/family_name") != "ؤ��") {
                command("say �㻹��ȥ������ɿ����ɡ�");
                return;
        }
        if ((int)ob->query("gb/bags") >= 2
         && ob->query("family/family_name") != "ؤ��" ) {
                command("say ؤ����ݲ��������ֱ��������С�ˣ�");
                command("kill "+ob->query("id"));
                return;
        }
        if ((int)ob->query("gb/bags") < 3 ) {
                command("say ���ڰ��е�������ǳ����Щ������˵�ɣ�");
                return;
        }
        if ( ob->query("shen") <0 || ob->query("shen") < ob->query("combat_exp")/2) {
                command("say ���������ã��ٶ���������°ɡ�");
                return;
        }
        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
        command("recruit " + ob->query("id"));
        ob->set("title",sprintf(HIR"ؤ������%s������"NOR,
                chinese_number(ob->query("gb/bags"))) );
        ob->set("gb/fenduo","����");
        ob->set("class","beggar");
}

string ask_dao()
{
        object me;
        object *list;

        me = this_player();

        if ( me->query("family/family_name") != "ؤ��")
                return RANK_D->query_respect(me) +
                "����ؤ��ú�����֪�˻��Ӻ�̸��";

        if ( me->query("family/master_name")!="������" && me->query("family/master_name")!="���߹�" )
                return RANK_D->query_respect(me) +
                "���������õ��ӣ��γ����ԣ�";

        if ( me->query_temp("fadao/asked"))
        	return "�ղ��㲻���ʹ���ô��";

        if ( present("fa dao", me))
                return RANK_D->query_respect(me) +
                "�����㲻����������";

        list = filter_array(objects(), (: $1->query("id")=="fa dao":));
        if ( sizeof(list) > 8) {
        	me->set_temp("fadao/asked",1);
        	return "�����ֵ�����ִ�����Ȼ��";
        }

        new(BINGQI_D("blade/fadao"))->move(me);
	me->set_temp("fadao/asked",1);
        message_vision("$N�õ�һ��������\n",me);
        return "�ã������ȥ����Ѳ�ӣ����ֲ��ذ��ĵ��ӣ��͵ش��á�";
}
int ask_xiaofeng()
{
	object me = this_player();
	if(me->query(QUESTDIR2+"over") && (!me->query(QUESTDIR3+"start")||!me->query_temp(QUESTDIR3+"ask_bai")))
	{
		if(!me->query_temp(QUESTDIR3+"ask"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ��ؤ���������϶��ڳ�������������������ʰɡ���\n"NOR,this_object());
	    me->set_temp(QUESTDIR3+"ask",1);
			return 1;
		}
		if(!me->query_temp(QUESTDIR3+"ask_chen"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ���³���Ҳ�ڣ�������������ʰɡ���\n"NOR,this_object());
			return 1;
		}
		if(!me->query_temp(QUESTDIR3+"ask_song"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ���γ��϶��ڳ���������������ʰɡ���\n"NOR,this_object());
			return 1;
		}
		if(!me->query_temp(QUESTDIR3+"ask_liang"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ�������϶��ڳ���������������ʰɡ���\n"NOR,this_object());
			return 1;
		}
		command("heng");
    me->set_temp(QUESTDIR3+"ask_bai",1);
    message_vision(HIC"$N��������������Ѿ���ף�����ȷʵ���Ǻ��ˣ���ʱ������֤�ĳ���ؤ�ﳤ��֮�⣬����̷��̷�š���Ǯ������й١���\n"NOR,this_object());
    message_vision(HIC"$N����һ�ٵ������ɺ�����Ϊ���ڸ���ʵ����Ȼɱ������������ʦ�����ջٵ���ׯ����ν���������ģ���Ȼ�����������ӣ���\n"NOR,this_object());
    me->set_temp(QUESTDIR3+"ask_bai",1);
		return 1;
	}	
	if(!me->query(QUESTDIR3+"start")&& me->query_temp(QUESTDIR3+"ask_bai")&&!me->query(QUESTDIR3+"over"))
	{
		message_vision(HIC"$N����¶��һ��ҧ���гݵ����ӡ�\n"NOR,this_object());
    command("say �������������֣��������ú��ˣ���ʱ��δ����������������������²���Ұ�ĳ��һ���������ˡ���"NOR);
		return 1;
	}	
	if(me->query(QUESTDIR3+"start")&&!me->query(QUESTDIR3+"over"))
	{
		message_vision(HIC"$N����¶��һ��ҧ���гݵ����ӡ�\n"NOR,this_object());
    command("say �������������֣��������ú��ˣ���ʱ��δ����������������������²���Ұ�ĳ��һ���������ˡ���"NOR);
		return 1;
	}	
	if(me->query(QUESTDIR3+"over"))
	{
		command("sigh");
		command("say ������Ҫ�ǻ������ǰ����ö��......"NOR);
		return 1;
	}	
	message_vision(HIC"$N��Ĭ��һ���ˣ�����������������ؤ�����ˡ���\n"NOR,this_object());
	return 1;
}
