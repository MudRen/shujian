// yang.c ����
// 4/4/97 -qingyun
// 16.10.98 snowman
// Modify By River@sj 99.6
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string dagger();
void create()
{
        set_name("����",({"yang xiao","yang","xiao"}));
        set("title", "���̹�����ʹ");
        set("nickname",WHT"��ң����"NOR);
        set("long", "���������̵Ĺ�����ʹ���ͷ�ң�ϳ���ң���ɵ����С�\n"+
                    "������һ���������Ȼ�������꣬������ȥ��ʮ��Ӣ��������\n");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen", -15000);
        set("str", 26);
        set("per", 29);
        set("int", 29);
        set("con", 27);
        set("dex", 30);         
        set("max_qi",4000);
        set("max_jing", 3000);
        set("eff_jingli", 3000);
        set("jiali", 80);
        set("combat_exp", 1600000);
        set("unique", 1);
        set("no_get",1);

        set("no_quest", 1);
        set_skill("sword",180); 
        set_skill("blade",180);
        set_skill("literate",150);
        set_skill("hand", 180);
        set_skill("strike", 180);
        set_skill("hanbing-mianzhang", 180);
        set_skill("yingzhua-shou", 180);
        set_skill("dodge",180);
        set_skill("force", 180);
        set_skill("piaoyi-shenfa", 180);
        set_skill("lieyan-dao",180);
        set_skill("liehuo-jian",180);
        set_skill("shenghuo-shengong", 180);
        set_skill("parry", 180); 

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
                "ذ������" : (: dagger :),
                "book" : (: dagger :),
                "������" : (: ask_me :),
                "�����׻�":"��˵�������˴��й�ѧ�����ҩ֮�����Ƴ�һ�ְ�����\n"
                        "�����������׻𵯡����в����Ի�ҩ����ǿ�����ɻ������䡣\n",
        ]));

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: exert_function, "tougu" :),
        }));
        setup(); 
        if( random(10) > 5)
        carry_object(BINGQI_D("changjian"))->wield();
        carry_object("/d/mingjiao/obj/white-cloth")->wear();
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
        if(fam["master_name"] == "��ң"){
                command("say ��ң���ɲ������ң���Ȼ�����������æ�������ʱ��������ɡ�");
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
 
void init()
{
        object me, ob;
        mapping fam;
        ::init();
        ob = this_player();
        me = this_object();        
	if(interactive(ob) && !wizardp(ob)
	 && base_name(environment(me))=="/d/mingjiao/longwang"
	 && ((fam = ob->query("family")) && fam["family_name"] != "����" )){
		command("say ���������̵��صأ���˵�����ˣ�������������Ҳ��������������Ͽ��뿪�˵أ�");
		command("consider "+ob->query("id"));  
		remove_call_out("kill_ob");
		call_out("kill_ob", 5, ob); 
	}
	if(interactive(ob) && ob->query_temp("mj_jiaozhu"))           
		command("nod "+ob->query("id"));   
	else 
		command("hehe "+ob->query("id"));      
}

string dagger()
{
	mapping fam = this_player()->query("family");
	object ob;        
	if(!fam || fam["family_name"] != "����")
		return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";

	if(this_player()->query_skill("dagger",1) > 100)
		return "���ذ���Ѿ���һ�������ˣ��Ȿ�����ûʲô�ã������������˰�";        

	if(! this_player()->query_skill("jiuyang-shengong", 1))
	if(this_player()->query_skill("shenghuo-shengong", 1) < 100)
		return "�������̵�ʱ���ж̣�����ʱ�������ɡ�";
	ob = unew("/clone/book/dagger-book");
	if(!clonep(ob))
		return "�������ˣ��ҵġ�ذ�����ۡ��Ѿ������������ˡ�";   
	if(clonep(ob) && ob->violate_unique()){
		destruct(ob);
		return "�������ˣ��ҵġ�ذ�����ۡ��Ѿ������������ˡ�";  
	}      
	ob->move(this_player());
		return "�ðɣ�������������ġ�ذ�����ۡ����͸����ˡ�";
}

string ask_me()
{ 
	mapping fam; 
	object ob, *clone;
	int i, j;

	if(!(fam = this_player()->query("family")) || fam["family_name"] != "����")
		return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";
	if(! this_player()->query_skill("jiuyang-shengong", 1))
	if(this_player()->query_skill("shenghuo-shengong", 1) < 100)
		return "�������̵�ʱ���ж̣�û��Ȩ��ʹ�������";
	if(!this_player()->query_skill("shenghuo-lingfa"))
		return "���ֲ�ʹ��������������ʲô��";
	ob=present("tieyan ling",this_player());
	if(ob && ob->query_amount() >= 2)
		return "�����϶��Ѿ���ô���ˣ���Ҫ���ʲô��";
	ob=unew(BINGQI_D("tieyan-ling"));        
	if(!clonep(ob)) return "�������ˣ��������Ѹ�ȫ������ȥ�ˡ�"; 
	i = ob->query("unique");
	clone = filter_array(children(base_name(ob)), (: clonep :));
	j = sizeof(clone);
	while (j--) if (!clone[j]->query("clone_by_wizard")) i--; 
	if(clonep(ob) && i < 0){
		destruct(ob);
		return "��Ǹ���������ˣ��������Ѹ�ȫ������ȥ�ˡ�";
	}
	ob->move(this_player());
	return "�ðɣ���������������ȥ�ɣ����㲻Ҫ����Ϊ�񣬶�෢չ�����̽��ڡ�";
}
