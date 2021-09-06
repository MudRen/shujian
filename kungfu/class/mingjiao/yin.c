// NPC yin.c ������
// Modify By River@sj 99.06
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_book();
void create()
{
        set_name("������",({"yin tianzheng","yin","tianzheng"}));
        set("title","���̻��̷���");
        set("nickname",HIW"��üӥ��"NOR);
        set("long", "���������̵��Ĵ󻤷�֮һ��һ����Ŀ����ͺ�����ߡ�\n"+
                    "����üʤѩ�������۽ǣ����ӹ���������ӥ�졣\n");                    
        set("age", 61);
        set("attitude", "peaceful");
        set("shen", -13000);
        set("str", 35);
        set("per", 20);
        set("int", 25);
        set("con", 28);
        set("dex", 25);        
        set("max_qi", 3000);
        set("max_jing", 2700);
        set("eff_jingli", 2500);
        set("jiali", 70);
        set("combat_exp", 1300000);
        set("unique", 1);
        
        set_skill("dodge",150);
        set_skill("force", 150);
        set_skill("literate",110);
        set_skill("piaoyi-shenfa", 150);
        set_skill("shenghuo-shengong", 140);
        set_skill("yingzhua-shou",190);
        set_skill("hand",190); 
        set_skill("parry", 150);        
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("hand", "yingzhua-shou");
        map_skill("parry", "yingzhua-shou");
        prepare_skill("hand","yingzhua-shou");

        create_family("����", 36, "����");
        set("inquiry", ([
                 "����" : (: ask_me :),
                 "�׺罣" : (:ask_me :),
                 "ӥצ�ַ�" : (: ask_book :),
        ]));
        setup();
        carry_object("/d/mingjiao/obj/yel-cloth")->wear();
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
        if (fam["generation"] == my_fam["generation"]){
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"�Ѱݹ���ʹΪʦ��"+RANK_D->query_self(me)+"����������Ϊͽ��");
                return;
                }
        if ((int)ob->query_skill("shenghuo-shengong", 1) < 100) {
                command("say Ҫѧ��Ϊ������书�������и�����ڹ���Ϊ��"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ����ʥ�����϶��µ㹦��");
                return;
                }     
        if ((int)ob->query_str() < 28) {
                command("say ��ѧ�ҵ�ӥצ�ַ�������Ҫ���㹻��������");
                command("say �ڱ������棬"+RANK_D->query_respect(ob)+"�Ƿ��Ӳ��˵㣿");
                return;
                }   
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title", HIW"���̰�üӥ�����½���"NOR);
}

string ask_me()
{
	object me = this_player();
        object ob;

        if (!me->query("family") || me->query("family/family_name") != "����")
        	return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��"; 

        if (me->query("combat_exp") < 100000)
        	return RANK_D->query_respect(me)+"�����������������²��ܱ�ס��ѱ�����";

        ob=unew(BINGQI_D("sword/baihong-jian"));
        if(!clonep(ob)) return "�������ˣ��ҵİ׺籦���Ѹ����������ˡ�";  
        if(clonep(ob) && ob->violate_unique()){
           destruct(ob);
           return "�������ˣ��ҵİ׺籦���Ѹ����������ˡ�";
        } 
        ob->move(me);
        return "�ðɣ���Ѱ׺籦�������ȥ�ɣ����㲻Ҫ����Ϊ�񣬳�Ϊ�������塣";
}

string ask_book()
{
        mapping fam; 
        object ob;
        if(!(fam = this_player()->query("family")) || fam["family_name"] != "����")
            return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��"; 
        if(this_player()->query_skill("hand", 1) > 30 )
            return RANK_D->query_respect(this_player())+"�����Ѿ�����Ҫ�Ȿ���ˣ����������������̵����ðɣ�";
        ob = unew("/d/mingjiao/obj/hand_book");
        if(!clonep(ob)) return "�������ˣ���ӥצ�ַ����Ѿ�����ʦ����ȥ�ˡ�";
        if(clonep(ob) && ob->violate_unique()){
           destruct(ob);
           return "�������ˣ���ӥצ�ַ����Ѿ�����ʦ����ȥ�ˡ�";
        } 
        ob->move(this_player());
        return "�ðɣ��Ȿ��ӥצ�ַ������û�ȥ�ú����С�";
}

void die()
{
        object me,sword;
        me = query_temp("last_damage_from");
	if (objectp(me))
        if (clonep()) {
          sword = unew(BINGQI_D("sword/baihong-jian"));
          if (!sword) sword = unew(BINGQI_D("changjian"));
          message_vision("\n$N���������������ѳ�һ��"+sword->name()+"��\n", me);
          sword->move(me); 
        }
        ::die();
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

        
        if (userp(ob) 
         && ob->query("family/family_name") == "����") {
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
