// wuxiuwen.c ������

inherit NPC;
int ask_ji();
void consider();

void create()
{
        set_name("������", ({ "wu xiuwen","wu","xiuwen" }) );
        set("gender", "����" );
        set("age", 26);
        set("long", "����޳�����Ŀ���ʣ�һ���������ź����\n");
        set("attitude", "friendly");
        set("str", 35);
        set("con", 30);
        set("int", 20);
        set("dex", 30);


        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 2000);
        set("eff_jingli", 1500);
        set("max_neili", 2000);
        set("jiali", 100);
        set("shen", 6500);
        set("combat_exp", 850000);
        set("startroom","/d/xiangyang/cross2");

        set_skill("force", 140);
        set_skill("strike", 140);
        set_skill("blade", 140);
        set_skill("dodge", 140);
        set_skill("parry", 140);
        set_skill("huntian-qigong", 140);
        set_skill("literate", 140);
        set_skill("xianglong-zhang", 150);
        set_skill("liuhe-daofa", 140);
        set_skill("xiaoyaoyou", 140);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "strike.xiao" :)
        }));

        map_skill("force", "huntian-qigong");
        map_skill("blade","liuhe-daofa");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("strike", "xianglong-zhang");
        map_skill("parry", "xianglong-zhang");
        prepare_skill("strike", "xianglong-zhang");

        create_family("ؤ��", 19, "��������");

	set("inquiry", ([
		"�л���" : (: ask_ji :),
		"����" : "��Ҳ֪������������������Ĺ���������������Ҫ����ѧ����ô������\n",
		"��ܽ" : "������һ��ܺã���׼���������������š�\n",
		"����" : "���СѾͷ�����첻֪������Щʲô��\n",
		"����" : "����ĸ�����ֲ�Ҫ����ҽУ�\n",
		"���߹�" : "�����˼���Խл����ˣ���γ����ұ�����Ҫ������ֻ�л�����ȥ�ġ�\n",
		"�����" : "��Ҳϲ����ܽ��ֻ�����Ƕ���֪����ܽ���ﵽ����ô�롣\n",
		"����ͨ" : "���ϵüҸ������������˼ҵ���Ϣ��\n",
		"һ�ƴ�ʦ" : "���ǻ�ү��һ��ָ�������¡�\n",
		"����" : "��Ǹ�����㲻��Ϥ���Ҳ������˵��\n",
		"rumors" : "��˵�ɹ�����Ҫ���������ˡ�\n",
	]));
        set("chat_chance", 5);
        set("chat_msg", ({
                "�������������Ҫ��ѧ�ù����������ɹ�����Ҳ��Ҳ...\n",
                "���������������֪��ܽ���ﵽ����ô��ġ���\n",
                 (: random_move :)
        }) );

        setup();
        carry_object(ARMOR_D("changshan"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

int ask_ji()
{
	object ob;
	ob=this_player();
	if (ob->query("shen")<=0){
		command("?");
		command("say �������������Ͳ�����ˣ�������ʶ�\n");
		return 1;
	}
	if (ob->query_temp("marks/jiaohua-ji") || ob->query_temp("marks/lost-ji") ){
		command("look "+ob->query("id")+"\n");
		command("say �ո�������..�����ݣ��Ұѽл���Ū����!�Ҳ���ȥ����ү����!\n");
		command("cry "+ob->query("id")+"\n");
		ob->delete_temp("marks/jiaohua-ji",1);
		ob->set_temp("marks/lost-ji",1);
		return 1;
	} else {
		command("dunno");
		return 1;
	}
}
