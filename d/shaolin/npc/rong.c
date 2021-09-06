inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������ʦ", ({ "kurong chanshi", "ku", "rong","chanshi","master" }) );
	set("nickname", "��������ɮ");
	set("gender", "����" );
        set("class","bonze");   
	set("age", 74);
	set("str", 30);
	set("cor", 27);
	set("cps", 32);
	set("int", 19);
        set("max_jing",3000);
        set("eff_jingli",3000);
        set("max_qi",4000);
        set("max_neili",4000); 
	set("max_force", 1500);
	set("force", 1500);
	set("force_factor", 70);
	set("rank_info/respect", "��ɮ");
	set("long", 
	"һ�����������ͯ�ӣ�����ɿ����ݹǵ���ɮ������ĸߴ󣬾�����˸��\n");
	create_family("������", 12, "����");
	set("combat_exp", 2000000);
	set("score", 200000);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	(: perform_action, "sword.qian" :)
	}) );
    set_skill("parry", 200);
    set_skill("dodge", 200);
    set_skill("force", 200);
    set_skill("finger", 200);
    set_skill("buddhism", 200);
    set_skill("literate", 200);
    set_skill("tianlong-shengong", 200);
    set_skill("yiyang-zhi", 200);
    set_skill("lingbo-weibu", 200);
    map_skill("dodge", "lingbo-weibu");
    map_skill("parry", "yiyang-zhi");
    map_skill("finger", "yiyang-zhi");
    map_skill("force", "tianlong-shengong");
    prepare_skill("finger","yiyang-zhi");
	set("inquiry", ([
	"name": "ƶɮ���ǿ���",
	]) );

	setup();
//	carry_object(__DIR__ "obj/cloth")->wear();
}
void attempt_apprentice(object ob)
{
  string old_name,new_name;
  if((int)ob->query_skill("buddhism",1)<120)
       {
         command("say �Ҷμ��书���ѧϢϢ��أ��ҿ�"+RANK_D->query_respect(ob)+"��������Ϊ�ƺ�������");
          return;
        }
       if((int)ob->query_skill("tianlong-shengong",1)<150)
        {
          command("say ����һ��ָ�ڹ���Ϊ��Ҫ���ҿ�"+RANK_D->query_respect(ob)+"�ƺ�Ӧ���������϶��µ㹦��");
          return;
        }
       command("smile");
        old_name = ob->query("name");
        new_name="��"+old_name[2..3];

       if ((string)ob->query("class")!="bonze")
       {       
        command("say ƶɮֻ�ճ��ҵ��ӣ�������ɮ������ȡ�");
        //command("chat  + old_name+ �����������³��ң���ɮ������ȡ�"\n);
        message_vision("������ʦ���һֻƤ����ͷ��������"+ob->query("name")+"��ͷ��һ������ʱͷ�����䡣\n",ob);
	}
        ob->set("name",new_name);
        ob->set("class","bonze");
        command("say ������������"+new_name);
        command("recruit " + ob->query("id") );
        command("chat ��������!");
        command("chat ���������ҵ�һ���ɴ��²�֮��,���ǿ�ϲ�ɺ�!");
        return;
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
      	ob->set("class", "bonze");
}
