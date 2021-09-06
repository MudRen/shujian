// Modified by Darken@SJ for tsjob

#include <ansi.h>;
inherit NPC;

int ask_tsjob();
int ask_tsjobtime();
int ask_tsj();

void create()
{
        object ob;
        set_name("���ŵ���", ({ "tianmen daoren", "daoren", "tianmen" }) );
        set("gender", "����");
        set("title", HIW"̩ɽ�ɵ�ʮ��������"NOR);
        set("class", "taoist");
        set("age", 55);
        set("attitude", "peaceful");
        set("unique", 1);
        set("str", 28);
        set("con", 18);
        set("dex", 20);
        set("int", 18);

        set("jiali", 120);
        set("combat_exp", 4450000);
        set("shen_type", 1);
        set("inquiry", ([
                "������" : "������������ͬ�ˣ����������ǰ���Ч�����ˡ���\n",
                "�������" : "�󵨣��㾡��ֱ������ʦү�����֣�\n",
//                "��ͽ" : (: ask_tsjob :),
                "����" : (: ask_tsjobtime :),
                "̩ɽ����" : (: ask_tsj :),
        ]));
        set("chat_chance", 3);
        set("chat_msg", ({
         	"���ŵ���ŭ���ɶ���������������ֻ��һʱ������������������֮λ��������˲ݲݡ����ݲݴ��ڡ�\n",
         	"���ŵ���̾Ϣ�����������������ˣ����������ܴ�����Ϊ���š�\n",
         	"���ŵ���ŭ�𣺡�������Ҫ���Ǿ����ո������һ\n",
        	(: command("sneer") :),
        	(: command("pei") :),
        }) );

        set_skill("sword", 350);
        set_skill("force", 350);
        set_skill("parry", 350);
        set_skill("dodge", 320);
        set_skill("cuff", 300);
        set_skill("yinyun-ziqi", 350);
        set_skill("taizu-quan", 280);
        set_skill("taishan-jianfa", 350);
        set_skill("qingmang-jianfa", 320);
        set_skill("literate", 200);
        set_skill("jingmai-xue", 160);
        set_skill("medicine", 160);

        map_skill("sword", "taishan-jianfa");
        map_skill("parry", "taishan-jianfa");
        map_skill("dodge", "qingmang-jianfa");
        map_skill("force","yinyun-ziqi");
        map_skill("cuff","taizu-quan");
        prepare_skill("cuff", "taizu-quan");

        create_family("̩ɽ��", 13, "����");
        setup();
        if (clonep())
        {
                ob = unew(BINGQI_D("sword/dongling_jian"));
                if (!ob)
                	ob = new(BINGQI_D("changjian"));
                ob->move(this_object());
                ob->wield();
                carry_object("/d/wudang/obj/white-robe")->wear();
        }
}

void attempt_apprentice(object ob)
{
        command("shake");
        command("say ̩ɽ���ֵ��ӽ��������ˣ�ƶ�����ݲ�����ͽ��");
        return;
}

int ask_tsjob()
{
        int i;
        object me = this_player();
        object target;

        if (me->query("combat_exp") < 1000000)
        {
                command("shake");
                command("whisper " + me->query("id") + " ������������ʺ��㣬�����鷳�ˡ�");
                return 1;
        }
        if (me->query_condition("tsjob_busy"))
        {
                command("whisper " + me->query("id") + " ��հ��ҽ���һ����ͽ������Ϣһ�°ɡ�");
                command("pat "+ me->query("id"));
                return 1;
        }
        if (me->query_condition("job_busy"))
        {
                command("whisper " + me->query("id") + " ��հ��ҽ���һ����ͽ������Ϣһ�°ɡ�");
                command("pat "+ me->query("id"));
                return 1;
        }
        if (me->query_temp("tsjob/asked"))
        {
                command("push");
                command("whisper " + me->query("id") + " ��ȥ׷�������˾��������ˣ�");
                return 1;
        }

        target = new(__DIR__"runner");
        me->set_temp("tsjob/target", target);
        me->set_temp("tsjob/asked", 1);
        me->apply_condition("tsjob",30);
        target->set("long", target->query("long") + "�ƺ��Ǵ�"+me->query("name")+"�������ѵġ�\n");
        target->set_name("̩ɽ����ͽ", ({ me->query("id")+"'s pantu"}) );
        i = me->query("max_pot")-100;
        if (me->query("combat_exp") > 2000000)
        {
	        target->add_temp("apply/defense", i);
	        target->add_temp("apply/attack", i);
        }
        target->set_skill("taishan-jianfa", i);
        target->set_skill("sword", i);
        target->set_skill("qingmang-jianfa", i);
        target->set_skill("dodge", i);
        target->set_skill("parry", i);
        target->set_skill("taizu-quan", i);
        target->set_skill("cuff", i);
        target->set_skill("yinyun-ziqi", i);
        target->set_skill("force", i);
        TASK_D->copy_status(me, target, 1);
        target->move(environment(this_object()));
        target->movement(0);
        command("whisper " + me->query("id") + " ��������һ�Ӹ����������ˣ���ͼ�������ɣ��ղ�ץ��һ����ͽȴ�����ˡ�");
        command("whisper " + me->query("id") + " ��Ϳ�����׷ȥ�����ö�˵ɱ�˱��ǣ�����Ȼ������ɽȥ�ˡ�");
        return 1;
}

int ask_tsj()
{
        object me = this_player();
        int i = me->query("ts_job");

        if (i < 1)
        {
                command("ugly " + me->query("id"));
                command("say ��Ϊ��̩ɽ������ʲô�ˣ�");
                return 1;
        }
        if (i < me->query("tsjf"))
        {
                command("hmm");
                command("say �ܽ���Ķ��Ѿ������ˣ������������");
                return 1;
        }
        command("ok tianmen");
        message_vision("$N��$nָ����һЩ̩ɽ�����Ľ�����\n", this_object(), me);
        me->add("tsjf",1);
        if (me->query_skill("taishan-jianfa",1) < 1)
                me->set_skill("taishan-jianfa",1);
        return 1;
}

int ask_tsjobtime()
{
        object me = this_player();
        int i = me->query("ts_job");
        string str;

        if (i < 1)
        {
                command("crazy " + me->query("id"));
                command("say �����û����׷����ͽ��");
                return 1;
        }
        command("wa2");
        str = "���ܹ����ҽ�����"+CHINESE_D->chinese_number(i)+"����ͽ��";
        command("say "+str);
        return 1;
}
