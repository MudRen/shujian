#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"�����ơ����Ʒ����ƪ"NOR, ({ "paiyun canpian", "paiyun", "canpian"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��ؤ�ｵ���Ƶľ�����ƪ������Լ���������ϲ�(hebing)��һ����ƪ��\n"
                );
                
                               set("value", 0);
                set("material", "skin");
                
        }
}
void init()
{
        
        add_action("do_hebing", "hebing");
}

int do_hebing(string arg)
{
int i,j,k;
object *inv, me = this_player();

if (!arg || arg == "")
return notify_fail("����ϲ�ʲô��\n");

if (arg != query("id")) 
return notify_fail("����ϲ�ʲô��\n");

if (this_player()->is_busy() || this_player()->is_fighting())
 return notify_fail("����æ���ء�\n");

inv = all_inventory(me);
k=1;
j=  sizeof(inv);

while(j--){

if (inv[j] != this_object() && inv[j]->query("id") == query("id"))
k++;
}
 if(k < 5) 
         return notify_fail("��Ҫ�ϲ��Ĳ�ƪ���������\n");  

 
message_vision(HIC "$N�Ȳ������ؽ�"HIR""+chinese_number(k)+""HIC""+this_object()->query("unit")+"��"+this_object()->query("name")+""HIC"���ϲ�����һ��ƪ��\n" NOR, me);  




if ( wizardp(me)) message_vision(HIM "kkkkkkk��"+k+"��\n" NOR, me);  
if ( wizardp(me)) message_vision(HIM "jjjjjjj��"+j+"��\n" NOR, me);  
        
j=sizeof(inv);
k=0;

while(j--){

if (inv[j] != this_object() && inv[j]->query("id") == query("id")&& k<4 )
{
        destruct(inv[j]);
  k++;
}
 
}

   destruct(this_object());                                 
 return 1;


}

