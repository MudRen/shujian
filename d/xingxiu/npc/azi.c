// azi.c ����
// Update by caiji@SJ 8/27/2000

inherit NPC;
inherit F_MASTER;

string ask_san();
string ask_for(object);
string ask_weng();
void create()
{
        set_name("����", ({ "azi", "a zi", "a" ,"zi"}));
        set("nickname", "������Сʦ��");
        set("long", "������Сʦ�á�һ�������µ���ò��Ů�����Ӱ׾���, ����������͸��һ��а����\n");
        set("gender", "Ů��");
        set("age", 15);
        set("attitude", "peaceful");
        set("env/wimpy", 110);
//	set("apprentice", 1);

        set("str", 18);
        set("int", 28);
        set("per", 30);
        set("con", 20);
        set("dex", 24);

        set("max_qi", 1400);
        set("max_jing", 1200);
        set("jiali", 10);
        set("combat_exp", 200000);
        set("shen", -1000);

        set_skill("force", 60);
        set_skill("huagong-dafa", 50);
        set_skill("dodge", 60);
        set_skill("zhaixingshu", 70);
        set_skill("strike", 60);
        set_skill("chousui-zhang", 60);
        set_skill("parry", 60);
        set_skill("poison", 60);
        set_skill("literate", 80);
        set_skill("claw", 60);
        set_skill("sanyin-zhua", 65);

        map_skill("claw", "sanyin-zhua");
        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixingshu");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "chousui-zhang");
        prepare_skill("claw", "sanyin-zhua");
        prepare_skill("strike", "chousui-zhang");

        create_family("������", 2, "����");

        set("inquiry", ([
                "������" : "������룬�Ͱ���Ϊʦ��\n",
                "�" : "�ٺ٣�������ô���׾͸����㡣\n",
                "���޺�" : "ȥ���޺���ʲô������Ϊʦ�͹���ѧ���ˡ�\n",
                "������" : "����������е���û��ûС�ġ��Ժ�����ɣ�\n",
                "����" : "��öവ�����ɣ���������г�ͷ֮�ա�\n",
                "����ľ��" : "�����˸��ҽ�������б������Լ�ȥ�á�\n",
                "���" : "���ҽ�����嶼��֪���������Ǹ�����ϡ�\n",
                "����" : "���ʵĿ��������ɣ�\n",
                "����" : "Ů�����׶��ˣ�����������ϲ�����еĵø��ӰѾ���\n",
                "��ҩ" : (: ask_san :), //add by caiji
		"����ɢ" : (: ask_san :), //add by caiji
		"����" : (: ask_for, "pifeng" :),//add by caiji
		"pifeng" : (: ask_for, "pifeng" :),//add by caiji
                "����" : (: ask_weng :), 
        ]));
        setup();
        set("pifeng_count",6);
        set("san_count",6);
        carry_object("/d/xingxiu/obj/yao");
	//add by caiji        carry_object("/d/xingxiu/obj/qxs");
	carry_object(ARMOR_D("baihu-qiu"))->wear();
}

void attempt_apprentice(object ob)
{
        if(ob->query("shen") > 0){
		command("say �㿴��ȥ���Ǹ����������ҲŲ��������ء�");
		return;
        }
	command("hehe " + ob->query("id"));
	ob->set("class","xingxiu");
	command("recruit " + ob->query("id"));
}

string ask_san()
{
        int exp;
        object drug, me, ob;
        mapping fam;

        me = this_object();
        ob = this_player();
        fam = (mapping)ob->query("family");
        exp=ob->query("combat_exp",1);

        if(!fam || exp < 80000 || fam["family_name"] != "������")
                return "��ƾ��Ҳ��Ҫ���޵Ķ��Ž�ҩ��\n";
        if( (int)ob->query_skill("huagong-dafa", 1) < 90 )//....caiji
                return "��Ļ����󷨹���̫ǳ������ô���������أ�\n";
        if(me->query("san_count") >= 1 && (!ob->query_temp("san_given"))){
                        me->add("san_count", -1);
                        drug = unew("/d/xingxiu/obj/qxs");
                        if (!clonep(drug)) return "����������������ʦ���������ˡ�\n";
                        drug->move(ob);
                        ob->set_temp("san_given", 1);
                        message_vision("$N��$n���˵�ͷ������$nһС������ɢ��\n", me, ob);
                        return "�Լ��þ����ˣ�ǧ��Ҫ�������ɵ��ӣ�\n";
        }
        if(ob->query_temp("san_given"))
                     return "�Ҳ��Ǹ���������\n";
        return "����������������ʦ���������ˡ�\n";
}

string ask_for(string name)
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_rude(this_player()) +
                "�ֲ������޵��ӣ�ƾʲô����Ҫ��Ҫ�ǵģ�";

        if (  present(name, this_player()) )
                return RANK_D->query_rude(this_player()) +
                "���������ϲ�����������������������Ҫ�ˣ� ����̰�����У�";

        if (query("pifeng_count") < 1)
                return "��Ǹ�������ò���ʱ�������Ѿ������ˡ�";

        ob = new("/d/xingxiu/obj/" + name);
        ob->move(this_player());

        add("pifeng_count", -1);

	message_vision("$N��$nһ��" + ob->query("name") + "��\n",this_object() ,this_player());

        return "����Ǽ��ö�������Ū���ˡ�";
}




string ask_weng()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_rude(this_player()) +
                "�ֲ������޵��ӣ�ƾʲô����Ҫ��Ҫ�ǵģ�";

       if ( !present("fanwen book", this_player()))
return "��˵ʲô����������...";
        
if (this_player()->query_temp("waweng"))
 return "����ô��ô̰������...";

        ob = new("clone/misc/weng");
        ob->set("owner",this_player()->query("id"));
        ob->move(this_player());
this_player()->set_temp("waweng",1);
	message_vision("$N��$nһ��" + ob->query("name") + "��\n",this_object() ,this_player());

        return "��ȥ�ɡ�";
}


