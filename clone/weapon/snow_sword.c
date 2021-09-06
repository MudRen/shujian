/*  <SecCrypt CPL V3R05>  */
 
#include  <weapon.h>

inherit  SWORD;

void  create()
{
                set_name("风回雪舞剑",  ({  "snowsword",  "xue  jian",  "sword"  })  );
                set_weight(400);
if( clonep() )
set_default_object(__FILE__);
       else {
                                set("unit",  "把");
                                set("value",  80000);
                                set("material",  "steel");
                                set("long",  "这是一把由百炼精钢精制而成的剑，剑身细长，轻巧锋利。\n");
                                set("wield_msg",  "$N从腰间抽出一把剑身细长的剑，舞了个剑花。\n");
                                set("unequip_msg",  "$N将手中的$n盘回腰间。\n");
                                set("weapon_prop/courage",  4);
}
                init_sword(140);
                setup();
}

