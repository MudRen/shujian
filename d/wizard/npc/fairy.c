// By action 
inherit NPC;
#include <ansi.h>
#include <mudlib.h>
#define DJTIME "dj_buchang2009215"
#define DJTIMES "2009年2月15日"

int ask_clear_divorce();
int ask_gender();
int ask_divorce();
int ask_new_pks();
int ask_gold_tb();
int ask_tb_gold();
mixed change_gift(string gift);

void create()
{
        set_name("小精灵", ({"fairy"}));
        set("title",HBGRN"「蓝妹妹」"NOR);
        set("long","一个可爱的小精灵，传说遇到她的人可以实现内心的一些愿望。\n");

        set("gender", "女性");
        set("attitude", "friendly");
        set("age", 18);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("per", 30);
        set("no_quest", 1);
        set("combat_exp", 100000);
        set("inquiry", ([


                    "更改姻缘" : (: ask_clear_divorce :),
                    "恢复性别" : (: ask_gender :),
                    "离婚"     : (: ask_divorce :),
                    "十恶不赦" : (: ask_new_pks :),
                    "兑换通宝" : (: ask_gold_tb :),
                    "兑换黄金" : (: ask_tb_gold :),
        ]));
        carry_object("/clone/misc/cloth")->wear();
        setup();
}


int ask_clear_divorce()
{
        int exp;
        object me = this_player();
        if (!me->query("divorce"))
        {
                command("say 你好像并没有离婚过吧？\n");
                return 1;
        }
        exp = me->query("combat_exp") * me->query("divorce") * 5 / 1000;
        if (exp > 300000)
            exp = 300000;
        command("say 如果想清除离婚记录，你将要被惩罚" + chinese_number(exp) + "点经验。\n");
        command("say 你确定要清除离婚记录吗(yes or no)?");
        input_to("confirm_clear_divorce", 1, me, exp);
        return 1;
}

int confirm_clear_divorce(string arg, object me, int exp)
{
        if (arg != "yes")
        {
                write("你放弃了清除离婚记录的想法。\n");
                return 1;
        }
        command("say 好吧，既然你决定了，我就帮你清除掉吧，以后记得要专一啊。\n");
        command("sigh " + me->query("id"));
        command("lover fairy");
        log_file("quest/clear_divorce", sprintf("[%s] %s清除离婚记录%d次，减少经验%d点.\n",
                ctime(time())[0..15], geteuid(this_player(1)), me->query("divorce"), exp));
        me->delete("divorce");
        me->add("combat_exp", -exp);
        me->setup();
        write(HIR"离婚记录清除完毕！共减少经验" + chinese_number(exp) + "点。\n"NOR);
        return 1;
}

int ask_gender()
{
        int exp;
        object me = this_player();
        if (me->query("gender") != "无性")
        {
                command("say 你身体十分健全，难道是脑子出了问题？\n");
                return 1;
        }
        exp = me->query("combat_exp");
        if (exp < 100000)
        {
                command("say 你经验太少了，高点再来吧。\n");
                return 1;
        }
        exp = exp * 5 / 100;
        if (exp > 300000)
                exp = 300000;
        command("say 如果想恢复性别，你将要被惩罚" + chinese_number(exp) + "点经验。\n");
        command("say 你确定要恢复性别吗(yes or no)?");
        input_to("confirm_gender", 1, me, exp);
        return 1;
}

int confirm_gender(string arg, object me, int exp)
{
        if (arg != "yes")
        {
                write("你放弃了恢复性别的想法。\n");
                return 1;
        }
        command("say 好吧，既然你决定了，我就帮你恢复吧，这种法术难度是非常大的，唉。\n");
        command("poor fairy");
        command("sweat fairy");
        me->delete_skill("pixie-jian");
        me->set("class", me->query("class_old"));
        me->set("gender", "男性");
        me->add("combat_exp", -exp);
        me->setup();
        log_file("quest/clear_divorce", sprintf("[%s] %s恢复性别为男性，减少经验%d点.\n",
                ctime(time())[0..15], geteuid(this_player(1)), exp));
        write(HIR"性别恢复完毕！共减少经验" + chinese_number(exp) + "点。\n"NOR);
        return 1;
}

int ask_divorce()
{
        object me = this_player();
        string id = me->query("marry/id");
        int last_on = FINGER_D->get_last_on(id);

        if (!me->query("marry"))
        {
                command("say 你没有结婚，来问什么？\n");
                return 1;
        }
        if (!last_on)
        {
                command("say 你的" + (me->query("gender") == "男性"?"娇妻":"夫君") + "呢？\n");
                return 1;
        }
        if ((time() - last_on) / 86400 < 30)
        {
                command("say 你的" + (me->query("gender") == "男性"?"娇妻":"夫君") + "最近才登陆过，这样不好吧？\n");
                return 1;
        }
        command("say 你真的想离婚吗(yes or no)?");
        input_to("confirm_divorce", 1, me);
        return 1;
}

int confirm_divorce(string arg, object me)
{
        if (arg != "yes")
        {
                write("你放弃了离婚的想法。\n");
                return 1;
        }
        command("say 好吧，既然你决定了，我就成全你吧。\n");
        command("sigh " + me->query("id"));
        command("lover fairy");
        me->delete("marry");
        me->add("divorce", 1);
        return 1;
}

int ask_new_pks()
{
        object me = this_player();
        

        if (me->query("PKS") >= 50 )
        {
                command("say 你不已经是恶人了么？\n");
                return 1;
        }
            if ((int)me->query_skill("jiuyin-baiguzhua",1) < 1)
        {
                command("say 你还没研究九阴真经武学。\n");
                command("addoil " + me->query("id"));
                return 1;
        }

            if ((int)me->query_skill("jiuyin-baiguzhua",1) > 1 )
        {
                me->add("PKS", 50);
        }
        command("say 好吧，你去做恶人去吧。\n");
        command("sigh " + me->query("id"));
        return 1;
}


int ask_gold_tb()
{
        object me = this_player();  
        
        	if (!userp(me))
        {
                command("say 作为书剑巫师没有必要这样吧\n");
                return 1;
        } 
        
        if ( me->query("balance") < 100000000 )
        {
                      command("say 你的"HIY"黄金存款"NOR"不足一万两，还是存着备用吧。\n");

                return 1;
        	
        }
        if ( me->query("balance") >= 100000000 )

        {
                me->add("balance",-100000000);
                me->add("SJ_Credit",100);
        }        
        tell_object(me,HIC"\n你成功将"HIY"一万锭黄金"HIC"存款转换为一百个"HBGRN+HIG"书剑通宝"NOR+HIC"！\n"NOR);
      return 1;
}

int ask_tb_gold()
{
        object me = this_player();  
        
        	if (!userp(me))
        {
                command("say 作为书剑巫师没有必要这样吧\n");
                return 1;
        } 
        if ( me->query("combat_exp") < 10000000 )
        {
                      command("say 对不起，你的实战经验不足10M，不能使用这项服务。\n");
                return 1;        	
        }

        
        if ( me->query("SJ_Credit") < 100 )
        {
                      command("say 你的"HBGRN+HIG"书剑通宝"NOR"太少了，无法兑换"HIY"黄金存款"NOR"。\n");
                return 1;        	
        }
         if ( me->query("balance") >= 600000000 )
{
                       command("say 你的"HIY"黄金存款"NOR"太多了，你就不怕溢出啊？\n");
                 return 1;          
}

        if ( me->query("SJ_Credit") >= 100 )
        {
                me->add("balance",100000000);
                me->add("SJ_Credit",-100);
        }        
        tell_object(me,HIC"\n你成功将一百个"HBGRN+HIG"书剑通宝"NOR+HIC"转换为"HIY"一万锭黄金"HIC"存款！\n"NOR);
      return 1;
}
