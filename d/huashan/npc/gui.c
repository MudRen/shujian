// /clone/npc/guishuxin
// by dubei
//by daidai ����quest

#include <ansi.h>
string ask_miji();
inherit NPC;
#define QUESTDIR "quest/��ɽ��/ӥ��������/"
void create()
{
        set_name("������", ({ "gui xinshu", "gui" }));
        set("long","�������������µĹ������������ƺ���ƽ�����ƺ�������ʲô�ر������\n");
        set("gender", "����");
        set("nickname", "��ȭ�޵�");
        set("age", 72);

        set("attitude", "friendly");
        set("shen", -9500);
        set("str", 35);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 7000);
        set("eff_jingli", 3500);
        set("unique", 1);

        set("max_jing", 2500);
        set("neili", 10000);
        set("max_neili", 8000);
        set("jiali", 150);
        set("combat_exp", 3000000);
        set("per",16);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "strike.tiangang" :)
        }));

        set_skill("strike", 220);
        set_skill("sword", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("xiantian-gong", 220);
        set_skill("tiangang-zhang",220);
        set_skill("quanzhen-jianfa", 200);
        set_skill("jinyan-gong",200);
        set_skill("literate", 100);
        set_skill("force", 200);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyan-gong");
        map_skill("strike","tiangang-zhang");
        map_skill("parry", "tiangang-zhang");
        map_skill("sword", "quanzhen-jianfa");
        prepare_skill("strike", "tiangang-zhang");

        create_family("��ɽ��", 10, "����");

        set("inquiry", ([
               "�ؼ��б�" : (: ask_miji :),
               "�ؼ�" : (: ask_miji :),
               "�б�" : (: ask_miji :),
        ]));

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

string *wheres=({
"/d/hz/baidi",          "/d/hz/baoshuta",               "/d/hz/cuihezhai",
"/d/hz/duanqiao",       "/d/hz/hongyuchi",              "/d/hz/huanglong",
"/d/hz/hubian",         "/d/hz/hupao",          "/d/hz/jiulou",
"/d/hz/tieqiang",               "/d/hz/longjing",               "/d/hz/huanglong",
"/d/hz/yuhuang",                "/d/hz/tianxiang",              "/d/hz/kuahong",
"/d/hz/majiu",          "/d/hz/jinhuazhai",             "/d/hz/yaopu",
"/d/hz/yuquan",                 "/d/hz/longjing",               "/d/hz/zahuopu",
});

string ask_miji()
{
        object me = this_player();
        object ob,room, obj;
        int p, i, exp, y, qi, neili, jingli,jing;

        if (!me->query("family")
         ||  me->query("family/family_name") != "��ɽ��"){
                command("sneer "+ me->query("id"));
                return "�����������б��ɴ����Ͳ����鷳���ˡ�";
        }
        if ( me->query_temp(QUESTDIR+"������/over") ){
                command("sneer "+ me->query("id"));
                return RANK_D->query_respect(me) + "�������ȥ���ؼ�����ʦ����";
        }
        if ( !me->query_temp(QUESTDIR+"start") ){
                command("sneer "+ me->query("id"));
                return RANK_D->query_respect(me) + "�Ǵ��������ģ�";
        }
        if ( me->query_temp(QUESTDIR+"����/over") ){
                  obj = new("/d/huashan/npc/obj/muxia");
                  obj->set("owner", me->query("id") );
                  obj->move(me);   
                  me->delete_temp(QUESTDIR+"����/over");
                  me->delete_temp(QUESTDIR+"start");
                  me->set_temp(QUESTDIR+"������/over", 1);
        command("say С���Ѿ������ˣ����Ƕ�л�ˡ�");
        message_vision("��������$Nһ��"HIW"ľϻ"NOR"��\n"NOR,me);
        return "�ؼ��б�������ľϻ֮�У������ȥ����ʦ���ɡ�";
                 }

                y = sizeof( filter_array(children("/d/huashan/npc/guizhong"),(:clonep:)));
        if(y > 0)
                return "����æ���أ���ʱû�пգ������ʱ�������ɡ�";
        p = random(sizeof(wheres));
        room= find_object(wheres[p]);
        if(!objectp(room)) return "����æ���أ���ʱû�пգ������ʱ�������ɣ�";
        i = me->query("max_pot")-100+random(30);
        exp = me->query("combat_exp");
        qi = me->query("max_qi");
        neili = me->query("max_neili");
        jing = me->query("max_jing");
        jingli = me->query("eff_jingli");
        ob= new("/d/huashan/npc/guizhong");
        ob->set_temp("target", me->query("id") );
// �������趨��������

        ob->set("combat_exp", exp );
        ob->set("max_qi", qi );
        ob->set("eff_qi", qi );
        ob->set("qi", qi );
        ob->set("max_jingli", jingli);
        ob->set("eff_jingli", jingli);
        ob->set("max_neili", neili*3/2);
        ob->set("neili", neili*3);
        ob->set("max_jing", jing);
        ob->set_skill("force", i);
        ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
        ob->set_skill("sword", i);
        ob->set_skill("cuff", i);
        ob->set_skill("zixia-gong", i);
        ob->set_skill("huashan-jianfa", i);
        ob->set_skill("huashan-shenfa", i);
        ob->set_skill("poyu-quan", i);

        ob->move(room);
        me->set_temp("guixinshu/ask", 1);
        message_vision(CYN"������¶��һ����Ϊ��֮ɫ��\n"NOR,me);
        command("say ʦ���Ǳ��ؼ��б�ȷʵ�����������ǰ���챻�Ҷ���ȥ����ͷ�ˡ�");
        return "�Ҷ��������ں������棬����Ұ����һ����ɡ�";
}

