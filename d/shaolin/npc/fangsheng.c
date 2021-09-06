
inherit NPC;

string ask_me_1(object);
//string ask_me_2(object);

void create()
{
	set_name("������ʦ", ({
		"fangsheng dashi",
		"fangsheng",
		"dashi",
	}));
	set("long",
		"����һλ��İ�С������ɮ�ˣ��������ƶ��ݡ�\n"
		"��ü��Ŀ��¶����������֮��\n"
	);
       set("nickname", "����������");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
    set("no_quest",1);

	set("age", 80);
	set("shen", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 3000);
	set("max_jing", 1300);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 40);
	set("combat_exp", 1600000);
	 
	set_skill("force", 180);
    set_skill("yijin-jing", 180);
	set_skill("dodge", 180);
	set_skill("shaolin-shenfa", 180);
	set_skill("strike", 180);
       	set_skill("parry", 180);
	set_skill("banruo-zhang", 180);
        set_skill("jingang-quan",180); 
set_skill("yizhi-chan",180);
set_skill("ruying-suixingtui",180);
set_skill("cuff",180);
set_skill("finger",180);
set_skill("leg",180);
	set_skill("buddhism", 180);
	set_skill("literate", 100);
    map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
        map_skill("parry", "banrou-zhang");
       //map_skill("cuff","jingang-quan");
	prepare_skill("strike", "banruo-zhang");
       prepare_skill("strike", "banruo-zhang");
	create_family("������", 35, "����");
        set("inquiry", ([
		"����" : (: ask_me_1, "gangchu" :),
		"��" : (: ask_me_1, "chaidao" :),
//      "�ӹ�" : (: ask_me_1, "naogou" :),
//		"����" : (: ask_me_1, "taosuo" :),
	 ]));
	set("weapon_count", 10);
//	set("tools_count", 5);

	setup();

        //carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (  present(name, this_player()))
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ�����������������������Ҫ�ˣ� ����̰�����У�";
//	if (!(this_player()->query("pass_xin"))
  //        return "����͵͵�����İɣ����ȥ��!\n";
             if (query("weapon_count") < 1)
		return "��Ǹ�������ò���ʱ�򣬶����Ѿ������ˡ�";
        ob = new("/d/shaolin/obj/" + name);
	ob->move(this_player());
	add("weapon_count", -1);
	message_vision("������$Nһ��" + ob->query("name") + "��\n", this_player());
	return "��ȥ�ɡ��ô���Ϊ���з���\n";
}
/*
string ask_me_2(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
       if (!(this_player()->query("pass_xin"))
          return RANK_D->query_respect(this_player())+"͵͵�����İɣ����ȥ��!\n";
       if (  present(name, this_player()) )
       return RANK_D->query_respect(this_player()) + 
	"���������ϲ�����������������������Ҫ�ˣ� ����̰�����У�";
	if (query("tool_count") < 1)
		return "�Ѿ�����ȥ��ɽ�ˣ�����ذɡ�";

    ob = new("/d/shaolin/obj/" + name);
	ob->move(this_player());

	add("tool_count", -1);

	message_vision("������$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ�����ô��﷭�����£�ȥ�ݼ���λǰ����ɮ��";
}*/
void attempt_apprentice(object ob)
{
	object me=this_object(); 
	mapping ob_fam, my_fam;
	string name, new_name;
//	me=this_object();
	my_fam =me->query("family");
	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

    	if ( !(ob->query("pass_xin")) )
	{
          command("say "+RANK_D->query_respect(ob) +"����ô������?");
           return;
       }
  	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}
	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��")
	{
		command("say " + ob_fam["master_name"] + "��ͽ����ô�ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
           name = ob->query("name");
           new_name = "��" + name[2..3];
           command("say ���Ĵ���֮�꣬�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");
           ob->set("name", new_name);
 		ob->set("title", "������ְ��ɮ");
           command("say �����ķ�������"+new_name+",��ϲ���Ϊ�������ֱ�ʥɮ֮             
                     һ\n");
	    command("say �ӽ��Ժ������������ְ�¸�ɮ�ˣ�����ú�����!\n");
	    command("recruit " + ob->query("id"));
		}
		else
	command("say " + RANK_D->query_respect(ob) + "�����Ǵ��ıĳ����ģ��㲻��Խ����ʦ��");
	return;
     }
