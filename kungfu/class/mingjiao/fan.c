// fan.c ��ң
// 4/4/97 -qingyun
// 16.10.98 snowman
// Modify By River@sj 99.6
//modify by looklove@sj 2000.11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
        set_name("��ң",({"fan yao","fan","yao"}));
        set("title","���̹�����ʹ");
        set("nickname",WHT"��ң����"NOR);
        set("long", "���������̵Ĺ�����ʹ�������кϳ���ң���ɵķ�ң��\n"+
                    "������һ���������Ȼ�������꣬������ȥ��ʮ��Ӣ��������\n");
        set("age", 56);
        set("attitude", "peaceful");
        set("shen", -10000);
        set("str", 26);
        set("per", 28);
        set("int", 29);
        set("con", 27);
        set("dex", 30);
        set("max_qi", 3500);
        set("max_jing", 2200);
        set("eff_jingli", 2500);
        set("jiali", 80);
        set("combat_exp", 1500000); 
        set("unique", 1);

        set_skill("sword",170); 
        set_skill("dodge",170);
        set_skill("force", 170);
        set_skill("blade",170);
        set_skill("literate",150);
        set_skill("hand",170);
        set_skill("strike",170);
        set_skill("hanbing-mianzhang",170);
        set_skill("yingzhua-shou",170);
        set_skill("piaoyi-shenfa", 170);
        set_skill("shenghuo-shengong", 170);
        set_skill("lieyan-dao",170);
        set_skill("liehuo-jian",170);
        set_skill("parry", 170);

        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("sword", "liehuo-jian");
        map_skill("parry", "liehuo-jian");
        map_skill("blade", "lieyan-dao");
        map_skill("hand", "yingzhua-shou");
        map_skill("strike", "hanbing-mianzhang");
        prepare_skill("strike", "hanbing-mianzhang");
        prepare_skill("hand","yingzhua-shou");

        create_family("����",35,"ʹ��");

        set("inquiry", ([
                 "���������" : (: ask_me :),
        ]));
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: exert_function, "tougu" :),
	}));
        setup();
        if ( random(10) > 5 )
        carry_object(BINGQI_D("blade"))->wield();
        carry_object("/d/mingjiao/obj/white-cloth")->wear();
}


void init()
{
	::init();
        add_action("do_kill", "kill");
        add_action("do_kill", "tk");
        add_action("do_kill", "teamkill");
        add_action("do_kill", "hit");
}
void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping fam = ob->query("family");
        mapping my_fam = me->query("family");
        if(!fam || fam["family_name"] != "����"){
                command("say "+RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return;
                }
        if(fam["master_name"] == "���޼�"){
                command("haha");
                command("say "+RANK_D->query_respect(ob)+"���ǽ����״����ӣ�"+RANK_D->query_self(me)+"����������Ϊͽ��"); 
                return;
                }
        if(fam["master_name"] == "����"){
                command("say ��ң���ɲ������ң���Ȼ����������·�æ�������ʱ��������ɡ�");
                ob->set("title", this_object()->query("title")+"���µ���");
                command("recruit " + ob->query("id"));
                return;
                }
        if (fam["generation"] > (my_fam["generation"] + 2)){
                command("say ���ҿ���Ӧ��������λ��������ѱ���ѧ��������");
                return;
                }
        if ((int)ob->query_skill("shenghuo-shengong", 1) < 120) {
                command("say Ҫѧ��Ϊ������书�������и�����ڹ���Ϊ��"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ����ʥ�����϶��µ㹦��");
                return;
                }
        if ((int)ob->query_int() < 30) {
                command("say ��ң���ɵ��书�����ӣ�Ҫѧ����Щ�书���ǵ��м��ߵ����ԡ�");
                command("say �����Է��棬"+RANK_D->query_respect(ob)+"�Ƿ񻹲�����");
                return;
                }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title", HIW+this_object()->query("title")+"���µ���"NOR);
}

string ask_me()
{
	mapping fam; 
	object ob, *clone;
	int i, j;

	if(!(fam = this_player()->query("family")) || fam["family_name"] != "����")
		return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";

	if (! this_player()->query_skill("jiuyang-shengong"))
	if(this_player()->query_skill("shenghuo-shengong", 1) < 50)
		return "�������̵�ʱ���ж̣������������㻹�����ʸ�ʹ�á�";

	if(this_player()->query_temp("marks/��1"))
		return "�㲻�Ǹ����˺��������������ô��Ҫ��";

	if(present("heiyu duanxugao", this_player()))
		return "�����ϲ��Ǵ��ź������������ô��Ҫ��";

	if ((int)this_player()->query("eff_qi") == (int)this_player()->query("max_qi"))
		return "�����ڲ���Ҫ�ú�������ࡣ";

	ob=unew(MEDICINE_D("heiyu"));        
	if(!clonep(ob)) return "�������ˣ�����������Ѹ�ȫ������ȥ�ˡ�"; 
	i = ob->query("unique");
	clone = filter_array(children(base_name(ob)), (: clonep :));
	j = sizeof(clone);
	while (j--) if (!clone[j]->query("clone_by_wizard")) i--; 
	if(clonep(ob) && i < 0){
		destruct(ob);
		return "��Ǹ���������ˣ�����������Ѿ�û���ˡ�";
	} 
	ob->move(this_player());
	this_player()->set_temp("marks/��1",1);
	return "�ðɣ���к�������������ȥ�ðɡ�";
}

int do_kill(string arg)
{
	object ob,ob2; 
	object me = this_player();
	ob2 = this_object();

	if (!arg) return 0;
	ob = present(arg, environment(me));
	if (ob == this_object() || ob == me) return 0;
	if (!ob || !ob->is_character()) return 0;
        
	if (userp(ob) && ob->query("family/family_name") == "����") {
                if (me->query("family/family_name") == "����") { 
			message_vision(ob2->name()+"��$N�ȵ�����Ϊ���̵��ӣ���Ȼɱ�Լ���ͬ�ţ��������㣡\n", me);
		}
		else {
			message_vision(ob2->name()+"��$N�ȵ����󵨿�ͽ����Ȼ����������Ұ��\n", me);
			kill_ob(me);
		}
		me->set("vendetta/����", 1);
		return 1;
	}
	return 0;
}
