// Skill: Emei-ChangQuan.c ¶ëÃ¼³¤È­
// Date : AHA 97/06/22

inherit SKILL;

mapping *action = ({
(["action" : "$NÉíÐÎÄýÖØ£¬×óÈ­»¯ÕÆºÍÓÒÈ­Ïà½Ó£¬Í¬Ê±´ÓÐØÇ°ÕýÖÐÍÆ³ö£¬"
               "Ò»ÕÐ¡¸ÆðÊÖÊ½¡¹»÷Ïò$nµÄÐØ¿Ú",
  "force" : 80,
  "dodge" : 20,
  "skill_name" : "ÆðÊÖÊ½",
  "damage_type" : "ðöÉË"
]),
(["action" : "$N²½·¨Áé¶¯£¬Ê¹³öÒ»ÕÐ¡¸Ç§½ïÍÈ¡¹£¬ÓÒ½Å½Å¼â¹´ÆðµÅÌß$nµÄ$l",
  "force" : 100,
  "dodge" : 15,
  "skill_name" : "Ç§½ïÍÈ",
  "damage_type" : "ðöÉË"
]),
(["action" : "$N×óÊÖÎÕÈ­Ïò×óÉÏÌô¸ñ£¬ÓÒÈ­Ç°³å£¬Ò»ÕÐ¡¸µ±ÐÄ´¸¡¹»÷Ïò$nµÄÐØ¿Ú",
  "force" : 110,
  "dodge" : 10,
  "skill_name" : "µ±ÐÄ´¸",
  "damage_type" : "ðöÉË"
]),
(["action" : "$N²½·¨Ò»±ä£¬Ë«È­ÃÍµØ´ÓÏÂÍùÉÏ¶¶´ò£¬Ò»ÕÐ¡¸ó«òëÊÖ¡¹»÷Ïò$nµÄ$l",
  "force" : 120,
  "dodge" : 15,
  "skill_name" : "ó«òëÊÖ",
  "damage_type" : "ðöÉË"
]),
(["action" : "$NÖØÐÄÏÂ³Á£¬ÎÈ×¡¹­²½£¬Ê¹³ö¡¸Ë³·çÈ­¡¹£¬×óÈ­ÏÂÑ¹£¬ÓÒÈ­¹´»÷$nµÄ$l",
  "force" : 130,
  "dodge" : 20,
  "skill_name" : "Ë³·çÈ­",
  "damage_type" : "ðöÉË"
]),
(["action" : "$N×óÏ¥Î¢Çü£¬ÓÒ½Åµ¯Æð£¬Ò»ÕÐ¡¸ÈÕÔÂ½Å¡¹ÉÁµç°ãµØÍ¬Ê±»÷Ïò$nµÄ$l",
  "force" : 140,
  "dodge" : 25,
  "skill_name" : "ÈÕÔÂ½Å",
  "damage_type" : "ðöÉË"
]),
(["action" : "$NÒ»¸ö´í²½ÉÁ¿ª$nµÄ¹¥»÷£¬½Ó×ÅÒ»ÕÐ¡¸ºïÇÀÌÒ¡¹£¬Ë«È­·ÖÁ½Â·"
             "Í¬Ê±»÷Ïò$nµÄ$l",
  "force" : 150,
  "dodge" : 15,
  "skill_name" : "ºïÇÀÌÒ",
  "damage_type" : "ðöÉË"
]),
(["action" : "$NÉíÐÎÒ»±ä£¬×ªµ½$nµÄÉíºó£¬Ò»ÕÐ¡¸°ÔÍõÊÖ¡¹£¬ÓÒÈ­ÁÃ»÷$nµÄ$l",
  "force" : 160,
  "dodge" : 25,
  "skill_name" : "°ÔÍõÊÖ",
  "damage_type" : "ðöÉË"
]),
(["action" : "$N×ó½ÅµÅµØÌøÆð£¬Ò»ÕÐ¡¸Äñ·Ö³á¡¹£¬Ë«È­»¯ÕÆ£¬·Ö±ð»÷Ïò$nµÄ$l",
  "force" : 140,
  "dodge" : 15,
  "skill_name" : "Äñ·Ö³á",
  "damage_type" : "ðöÉË"
]),
(["action" : "$NÎÈ×¡ÉíÐÎ£¬×óÊÖÐé»Î£¬Ò»ÕÐ¡¸ÅüÉ½È­¡¹£¬ÓÒÈ­ÏòÇ°ÃÍ»÷$nµÄÍ·²¿",
  "force" : 170,
  "dodge" : 10,
  "skill_name" : "ÅüÉ½È­",
  "damage_type" : "ðöÉË"
]),
(["action" : "$NÃÍµØÌøÆð£¬×ó½ÅÂäÔÚ$nÓÒ½ÅÖ®Ç°£¬Ò»ÕÐ¡¸Áú°ÚÎ²¡¹£¬ÓÒÈ­Ë¦Æð»÷Ïò"
             "$nµÄ$l",
  "force" : 160,
  "dodge" : 20,
  "skill_name" : "Áú°ÚÎ²",
  "damage_type" : "ðöÉË"
]),
(["action" : "$NÂí²½Î¢³Á£¬Á¦¹áÈ­±³£¬Ò»ÕÐ¡¸Á¬ËÄÈ­¡¹£¬Ë«È­Èç·ç£¬´Ó×óÓÒÁ¬Ðø"
             "»÷Ïò$nµÄ$l",
  "force" : 180,
  "dodge" : 30,
  "skill_name" : "Á¬ËÄÈ­",
  "damage_type" : "ðöÉË"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
  if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
     return notify_fail("Á·¶ëÃ¼³¤È­±ØÐë¿ÕÊÖ¡£\n");
  return 1;
}

string query_skill_name(int level)
{
  return action[random(sizeof(action))]["skill_name"];
}

mapping query_action(object me, object weapon)
{
  int max_neili;
  float factor;
 
  mapping act = action[random(sizeof(action))];
  max_neili = me->query("max_neili");
  if(max_neili <= 100) return act;
  factor = sqrt(sqrt((float)max_neili/100.0));
  act["force"] = (int)((float)act["force"]*factor);
  act["dodge"] = (int)((float)act["dodge"]*factor);
  return act;
}

int practice_skill(object me)
{
  int level;
  if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
     return notify_fail("Á·¶ëÃ¼³¤È­±ØÐë¿ÕÊÖ¡£\n");
                  
  if((int)me->query("qi") < 30)
     return notify_fail("ÄãµÄÌåÁ¦Ì«µÍÁË¡£\n");

  level = (int)me->query_skill("emei-changquan", 1)/10;
  if(level >= 3){
    if((int)me->query("neili") < 20)
       return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·¶ëÃ¼³¤È­¡£\n");
    me->add("neili", -8);
  }
  me->receive_damage("qi", 20);
  return 1;
}

string perform_action_file(string action)
{
  return __DIR__"emei-changquan/" + action;
}
ÿ
