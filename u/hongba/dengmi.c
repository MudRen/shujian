// 灯谜
// by hongba
inherit ITEM;
#include <ansi.h>


 
void init()
{
        add_action("do_guess", "cai");
}

void create()
{
string str;

switch(random(19)){

case(0):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"七仙女嫁出去一个（打一成语）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","六神无主");
break;
case(1):         set_name(HIM"灯谜"NOR,({ "deng mi"}) );
set("long", "这是一幅灯谜，上面写着["HIR"扣押张学良（打一古人）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","关汉卿");

break;
case(2):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"愿用家财万贯，买个太阳不下山（4字教育用语）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","自费留日");
break;
case(3):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"劝君更尽一杯酒 (打一欧洲地名)"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","巴尔干");
break;
case(4):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"讹诈集体财产(打一红楼人名)"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","赖大家的");
break;
case(5):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );

set("long", "这是一幅灯谜，上面写着["HIR"元宵隔日始营业(打纸张类型)"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","十六开");
break;
case(6):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"穷人打官司（打一字）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","皓");
break;
case(7):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"当代胜过古代（打一水浒人名）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","史进");
break;
case(8):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"功夫不行（打一水浒人名）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","武松");
break;
case(9):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"哈哈哈，再见（打一书剑物品名称）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","三笑逍遥散");
break;
case(10):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"赵匡胤千里送京娘（打一书剑NPC名称）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","宋远桥");
break;
case(11):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"语数外理化生政地都行（打一书剑NPC名称）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","史松");
break;
case(12):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"爷爷捅人了（打一书剑NPC名称）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","血刀老祖");
break;
case(13):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"天下皆可去得（打一书剑NPC名称）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","任我行");
break;
case(14):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"望着苍峰（打一书剑NPC名称）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","张翠山");
break;
case(15):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"搬到山上去住（打一书剑NPC名称）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","乔峰");
break;
case(16):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"痊愈的挺快（打一书剑NPC名称或金说人物一）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","康敏");
break;
case(17):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"九月九登基（打一书剑NPC名称或金说人物一）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","王重阳");
break;
case(18):         set_name(HIM"灯谜"NOR,({ "deng mi" }) );
set("long", "这是一幅灯谜，上面写着["HIR"翼德浑身是胆（打一书剑NPC名称）"NOR"]大家可以试着(cai)它。\n");
set("unit", "幅");
set("answer","张无忌");
break;


        setup();
}

}

int do_guess(string arg)
{
        int c;
        int i;
       object me = this_player();
       c = 1+random(2);
        if(!arg)
        return 0;

         if (arg == query("answer")) {

                me->add("SJ_Credit", c);
              write(HIY "恭喜你，猜对啦。\n" NOR, me);
                write(HIY "你获得了"+CHINESE_D->chinese_number(c)+"个书剑通宝。\n" NOR, me);
             destruct(this_object());
             return 1;

        }
else 
return notify_fail("不对耶，再想想\n");

}
