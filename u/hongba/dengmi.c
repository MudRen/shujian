// ����
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

case(0):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"����Ů�޳�ȥһ������һ���"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","��������");
break;
case(1):         set_name(HIM"����"NOR,({ "deng mi"}) );
set("long", "����һ�����գ�����д��["HIR"��Ѻ��ѧ������һ���ˣ�"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","�غ���");

break;
case(2):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"Ը�üҲ���ᣬ���̫������ɽ��4�ֽ������"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","�Է�����");
break;
case(3):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"Ȱ������һ���� (��һŷ�޵���)"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","�Ͷ���");
break;
case(4):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"��թ����Ʋ�(��һ��¥����)"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","����ҵ�");
break;
case(5):         set_name(HIM"����"NOR,({ "deng mi" }) );

set("long", "����һ�����գ�����д��["HIR"Ԫ������ʼӪҵ(��ֽ������)"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","ʮ����");
break;
case(6):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"���˴��˾����һ�֣�"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","�");
break;
case(7):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"����ʤ���Ŵ�����һˮ�������"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","ʷ��");
break;
case(8):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"�����У���һˮ�������"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","����");
break;
case(9):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"���������ټ�����һ�齣��Ʒ���ƣ�"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","��Ц��ңɢ");
break;
case(10):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"�Կ�طǧ���;����һ�齣NPC���ƣ�"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","��Զ��");
break;
case(11):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"�������������ض��У���һ�齣NPC���ƣ�"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","ʷ��");
break;
case(12):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"үүͱ���ˣ���һ�齣NPC���ƣ�"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","Ѫ������");
break;
case(13):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"���½Կ�ȥ�ã���һ�齣NPC���ƣ�"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","������");
break;
case(14):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"���ŲԷ壨��һ�齣NPC���ƣ�"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","�Ŵ�ɽ");
break;
case(15):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"�ᵽɽ��ȥס����һ�齣NPC���ƣ�"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","�Ƿ�");
break;
case(16):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"Ȭ����ͦ�죨��һ�齣NPC���ƻ��˵����һ��"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","����");
break;
case(17):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"���¾ŵǻ�����һ�齣NPC���ƻ��˵����һ��"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","������");
break;
case(18):         set_name(HIM"����"NOR,({ "deng mi" }) );
set("long", "����һ�����գ�����д��["HIR"��»����ǵ�����һ�齣NPC���ƣ�"NOR"]��ҿ�������(cai)����\n");
set("unit", "��");
set("answer","���޼�");
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
              write(HIY "��ϲ�㣬�¶�����\n" NOR, me);
                write(HIY "������"+CHINESE_D->chinese_number(c)+"���齣ͨ����\n" NOR, me);
             destruct(this_object());
             return 1;

        }
else 
return notify_fail("����Ү��������\n");

}
