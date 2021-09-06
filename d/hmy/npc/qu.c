// qu.c ����
// Finish by action@SJ 2009.1.6
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("����", ({ "qu yang", "qu", "yang"}));
        set("long", "�������������ʮ����֮һ���书��ɲ⡣\n"+
		    "����������������֮�������տ��ԳƵ����ǵ�����һ��.\n");
        set("title",HIY"�������  "HIG"����"NOR);
        set("gender", "����");
        set("age", 60);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);

        set("max_qi", 3000);
        set("max_jing", 2200);
        set("eff_jingli", 2200);
        set("jiali", 90);
        set("combat_exp", 2000000);
        set("shen", -1000);
       
        set_skill("strike", 220);
        set_skill("hand", 220);
        set_skill("blade", 220);
        set_skill("parry", 220);
        set_skill("dodge", 220);
        set_skill("force", 220);
        set_skill("literate", 160);

        set_skill("tianmo-dao",220);
        set_skill("tianmo-zhang",220);
        set_skill("tianmo-shou",200);
        set_skill("ding-dodge",220);
        set_skill("tianmo-gong",220);
        set_skill("tianmo-jue",200);

        map_skill("force", "tianmo-gong");
        map_skill("strike", "tianmo-zhang");
        map_skill("parry", "tianmo-gun");
        map_skill("hand", "tianmo-shou");
        map_skill("blade", "tianmo-dao");
        map_skill("dodge", "ding-dodge");
        map_skill("strike", "tianmo-zhang");
        prepare_skill("strike", "tianmo-zhang");
        create_family("�������", 8, "����");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.jingshen" :),
                (: exert_function, "powerup" :),
        }));
	
        setup();
        
	carry_object(MISC_D("cloth"))->wear();  
	carry_object(BINGQI_D("blade"))->wield(); 
}

void attempt_apprentice(object ob)
{
     if(ob->query_skill("tianmo-gong",1) < 160 ||
      ob->query_skill("tianmo-zhang",1) < 160 ||
        ob->query_skill("tianmo-shou",1) < 160){
        command("say ����书��������죬�ٻ�ȥ�����ɡ�");
        return;
        }
     command("say �ã��������б�����Ƚ��������������㻹��������������ˡ�");
     command("recruit " + ob->query("id"));
}