// NPC: song.c �γ���
// Modify By Looklove 2000/10/18

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "begger.h";
int ask_xiaofeng();

#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
void create()
{
	set_name("�γ���", ({"song zhanglao", "song", "zhanglao"}));
	set("title", HIW"ؤ��Ŵ�����"NOR);
    	set("gb/bags",9);
    	set("nickname", "��������");
	set("gender", "����");
    	set("age", 65);
	set("long", "����ؤ��������֮һ��\n");
	set("attitude", "peaceful");

	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 28);

	set("qi", 2800);
	set("max_qi", 2800);
	set("jing", 1600);
	set("max_jing", 1600);
	set("eff_jing", 2600);
	set("neili", 3800);
	set("max_neili", 3800);
	set("jiali", 30);

    	set("combat_exp", 550000);

	set_skill("force", 140); // �����ڹ�
	set_skill("huntian-qigong", 140); // ��������
	set_skill("hand", 140); // ����ȭ��
        set_skill("suohou-shou", 140);
	set_skill("dodge", 135); // ��������
        set_skill("xiaoyaoyou", 140); // ǧ������
	set_skill("parry", 140); // �����м�
        set_skill("stick", 100);
        set_skill("dagou-bang", 100);
	set_skill("begging", 100);

	map_skill("force", "huntian-qigong");
        map_skill("hand", "suohou-shou");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "suohou-shou");
	map_skill("stick", "dagou-bang");
	prepare_skill("hand", "suohou-shou");

	create_family("ؤ��", 18, "�Ŵ�����");

        set("inquiry", ([
                "ؤ��" : "����ؤ�������µ�һ��\n",
                "����" : "����Ķ���ȥ��\n",
                "�Ƿ�" : "�����������壬���ǵ�ǰ�ΰ�����\n",
		            "����" : (: ask_xiaofeng :),
		            "���־���" : (: ask_xiaofeng :),
		            "ؤ������" : (: ask_xiaofeng :),
		            "���־��" : (: ask_xiaofeng :),
		            "�򹷰���" : "�򹷰��˱������֮�����������ǰ���������\n"
			     "��ϧ�ǰ���һȥ�����о���Ҳû�˻��ˣ���������\n"
			     "��˵������Ƥ���ճ�һ������������Ǽ������ϣ�\n"
			     "����һ�飬��Ħ���ã���ֻ������һ��㡣\n",
		"��Ħ" : "����ֻ����ƾ��һ���ǰ��������ս����ׯ��ͼ����\n"
			 "ϣ���ܴ�������򹷰��������£�˵������������ \n"
			 "���򲻳�ʲô�򹷰�����������������ֻ����һ��㡣\n",
		"ͼ��" : "������֪�ĸ�������������͵ȥ�ˣ�\n"
        ]));
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        	(: perform_action, "stick.chan" :),
        	(: exert_function, "huntian" :),
	}));

	setup();
	carry_object(__DIR__"obj/gb_budai9")->wear();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
        carry_object(BINGQI_D("zhubang"))->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() <=25	) {
		command("say �ҵĹ������ǿ��" +
		RANK_D->query_respect(ob) +
		"������̫�����ƺ����ʺϸ���ѧ�书��\n");
		return;
	}

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

	if( ob->query_skill("huntian-qigong", 1) < 50){
		command("say "+RANK_D->query_respect(ob) +"�Ļ��������ǲ��ǻ�������");
		return;
	}
        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
        if (!ob->query("gb/bags")) ob->set("gb/bags", 1);
        command("recruit " + ob->query("id"));
        ob->set("title",sprintf("ؤ���ܶ�%s������",
                chinese_number(ob->query("gb/bags"))) );
        ob->set("class","beggar");
}
int ask_xiaofeng()
{
	object me = this_player();
	if(me->query(QUESTDIR2+"over") && !me->query(QUESTDIR3+"start"))
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
      me->set_temp(QUESTDIR3+"ask_song",1);
      message_vision(HIC"$N̾�˿����������������壬�����Ǹ�װǻ���ƵĴ���ۣ������Ǹ�ֱ��ֱ�ǵĺú��ӣ�����ĳû���·ֱ档���������ϰɡ���\n"NOR,this_object());
			return 1;
		}
		if(!me->query_temp(QUESTDIR3+"ask_liang"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ�������϶��ڳ���������������ʰɡ���\n"NOR,this_object());
			return 1;
		}
		command("sigh");
    message_vision(HIC"$N����һ�ٵ����������˵����ǣ��̫�࣬���˳�ȥ��ؤ���ڽ�������Ҳ̧����ͷ��������Ҫ�����ǲ���ȥ�ʱ��˰ɡ���\n"NOR,this_object(),me);
		return 1;
	}	
	if(me->query(QUESTDIR3+"start")&&!me->query(QUESTDIR3+"over"))
	{
		message_vision(HIC"$N����¶��һ��ҧ���гݵ����ӡ�\n"NOR,this_object());
    command("say �������������֣��������ú��ˣ���ʱ��δ����������������������²������ĳ��һ���������ˡ���"NOR);
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
