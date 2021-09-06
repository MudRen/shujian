//  zhu.c

inherit NPC;
inherit F_VENDOR;

int ask_lost();
void create()
{
        set_name("���ϰ�", ({ "zhu laoban", "zhu", "laoban" }));
        set("shen_type", 1);

        set("gender", "����");
        set("age", 44);
        set("long", "��λ�ϰ���Ȼ����Ǯ�����ϴ����˽��ָ��\n");
        set_skill("unarmed", 24);
        set_skill("dodge", 21);
        set_temp("apply/damage", 18);

        set("combat_exp", 7000);
        set("attitude", "friendly");
        set("vendor_goods", ({
           (["name":__DIR__"obj/beauty_book","number":3]),
           (["name":BINGQI_D("yuxiao"),"number":5]),
           (["name":__DIR__"obj/necklace","number":20]),
           (["name":__DIR__"obj/goldring","number":25])
        }));
        set("inquiry", ([
		"��ʧ" : (:ask_lost:),
		"lost" : (:ask_lost:),
		]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        message_vision("$N��ɥ�ط������ƹ���ڸ߸ߵĹ�̨���棬��������\n", ob);
}

void unconcious()
{
        say( "���ϰ��ڻ�������һ������һ�������������򿪺��ӣ����һ��ҩ�����������\n");
        say( "Ƭ��֮�䣬���ϰ��ָֻ��˾��񣬡��ٺ١���Ц��������\n");
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
}

void die()
{
        unconcious();
}

int ask_lost()
{
	object me = this_player();
	
	if ( (mapp(me->query("token/ring"))) && (!present("ring", me)) )
	{
		me->set_temp("token_lost","ring");
		command("say ǰ�����һ��˶�ǧ�������չ���һ���׽��ָ,�ѵ����㶪�ģ�");
		return 1;
	}
	
	if ( (mapp(me->query("token/bangle"))) && (!present("bangle", me)) )
	{
		me->set_temp("token_lost","bangle");
		command("say ǰ�����һ��˶�ǧ�������չ���һֻ�������,�ѵ����㶪�ģ�");
		return 1;
	}
	
	if ( (mapp(me->query("token/jade"))) && (!present("jade", me)) )
	{
		me->set_temp("token_lost","jade");
		command("say ǰ�����һ��˶�ǧ�������չ���һ����������,�ѵ����㶪�ģ�");
		return 1;
	}
	
	if ( (mapp(me->query("token/necklace"))) && (!present("necklace", me)) )
	{
		me->set_temp("token_lost","necklace");
		command("say ǰ�����һ��˶�ǧ�������չ���һ����ˮ������,�ѵ����㶪�ģ�");
		return 1;
	}
	
	if ( (mapp(me->query("token/headgear"))) && (!present("headgear", me)) )
	{
		me->set_temp("token_lost","headgear");
		command("say ǰ�����һ��˶�ǧ�������չ�һ���ƽ�ͷ��,�ѵ����㶪�ģ�");
		return 1;
	}
	
	command("say �ѵ�����ð��ʧ�");
	return 1;
}

int accept_object(object me, object ob)
{
        int nmoney=ob->value();
        string str;
        object item;

        

        if(!str=me->query_temp("token_lost"))
                return notify_fail("���ϰ�˵������λ" + RANK_D->query_respect(me) + "����֪���б����ʲô�鱦��\n");
        if( ob->query("money_id") && nmoney >= 200000 ) 
        {
                item=new("clone/spec/item/"+me->query_temp("token_lost")+".c");
                command("say ����,���Ӳ���������,��"+item->query("name")+"�ͻ���"+ RANK_D->query_respect(me) + "�ɡ�\n");
                item->move(me);
                me->delete_temp("token_lost");
                return 1;
        }
        else
        {
                message_vision("���ϰ�Ц�����ҿ��ǻ��˶�ǧ������ѽ��\n", me);
                  return 0;
        }
}